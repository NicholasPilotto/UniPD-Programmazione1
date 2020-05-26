#include <iostream>

using namespace std;

struct nodo {
  int info;
  nodo* left;
  nodo* right;

  nodo(int x = 0, nodo* l = 0, nodo* r = 0) {
    info = x;
    left = l;
    right = r;
  }
};

// FUNZIONI AUSILIARIE FORNITE
nodo* buildTree(int arr[], int i, int n) {
  if (i >= n) {
    return NULL;
  }
  nodo* root = new nodo(arr[i]);
  // insert left child
  root->left = buildTree(arr, 2 * i + 1, n);
  // insert right child
  root->right = buildTree(arr, 2 * i + 2, n);

  return root;
}

int height(nodo* root) {
  if (!root) {
    return 0;
  }
  return 1 + max(height(root->left), height(root->right));
}

void stampa_l(nodo* r) {
  if (r) {
    cout << r->info << '(';
    stampa_l(r->left);
    cout << ',';
    stampa_l(r->right);
    cout << ')';
  } else {
    cout << '_';
  }
}

void sc(int* C) {
  cout << *C << ' ';
  if (*C != -1)
    sc(C + 1);
}

bool cerca_cam(nodo* r, int k, int y, int* C);

int main() {
  int dim;
  cin >> dim;
  int* a = new int[dim];
  for (int i = 0; i < dim; i++) {
    cin >> a[i];
  }

  nodo* root = NULL;
  root = buildTree(a, 0, dim);
  stampa_l(root);
  cout << endl;
  int h = height(root);
  int* C = new int[h]();

  int k, val;
  cin >> val >> k;

  bool b = cerca_cam(root, k, val, C);
  cout << endl;
  if (b) {
    cout << "trovato  cammino= ";
    sc(C);
    cout << endl;
  } else {
    cout << " nessun cammino con " << k << " valori=" << val << endl;
  }

  return 0;
}

// PRE=(albero(r) è ben formato e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è l'altezza di albero(r))
bool cerca_cam(nodo* r, int k, int y, int* C) {
  if (!k && !r->left && !r->right && !r->info == y) {
    *C = -1;
    return true;
  }

  if (k == 1 && !r->left && !r->right && r->info == y) {
    *C = -1;
    return true;
  }

  if (!k && r->info == y) {
    return false;
  }

  if (r->info == y) {
    if (r->left) {
      if (cerca_cam(r->left, k - 1, y, C + 1)) {
        *C = 0;
        return true;
      } else {
        if (cerca_cam(r->right, k - 1, y, C + 1)) {
          *C = 1;
          return true;
        }
      }
    } else if (r->right) {
      if (cerca_cam(r->right, k - 1, y, C + 1)) {
        *C = 1;
        return true;
      }
    }
  } else {
    if (r->left) {
      if (cerca_cam(r->left, k, y, C + 1)) {
        *C = 0;
        return true;
      } else {
        if (cerca_cam(r->right, k, y, C + 1)) {
          *C = 1;
          return true;
        }
      }
    } else if (r->right) {
      if (cerca_cam(r->right, k, y, C + 1)) {
        *C = 1;
        return true;
      }
    }
  }
  return false;
}
// POST= (restituisce true sse in albero(r) esiste un cammino da r ad una foglia con esattamente k
// nodi con campo info=y e false altrimenti) &&(in caso restituisca true, C contiene una sequenza (anche vuota)
// di 0/1 seguita da -1 e che individua il cammino più a sinistra in albero(r) con esattamente k nodi con campo info=y)

/*
  CASO BASE1: tutti gli k nodi con info = y ed il corrente nodo è una foglia diversa da y (riga 91):
    - questo caso base specifica l'eventualità del caso in cui tutti i k nodi con campo info = y sono stati
      trovati e i nodi left e right sono nulli, quindi siamo in una foglia e il percorso è stato trovato,
      si imposta il valore -1 nella cella corrente dell'array C e si ritorna TRUE

  CASO BASE2: ci troviamo in una foglia con campo info = y, k ancora = 1 (riga 96):
    - se k = 1 e il campo info di r = y, ed entrambi i nodi left e right sono nulli, significa che finora abbiamo trovato
      k-1 valori y, ci troviamo in una foglia e il suo campo info = y, quindi il k-esimo nodo, il percorso è chiuso.
      Si imposta la cella corrente di C uguale a -1 e si ritorna TRUE in quanto il percorso cercato è stato trovato.

  CASO BASE3: sono stati trovati tutti i k nodi = y, ma non siamo in presenza di una foglia (riga 100):
    - se tutti i k nodi con campo info sono stati trovati, ma il nodo corrente non è una foglia (i suoi nodi left e right
      non sono NULL), il corrente non è un percorso corretto, un quanto potrebbero esserci altri nodi = y. Si ritorna FALSE.

  CASO RICORSIVO: riga 105:
    - si controlla che il campo info del nodo corrente è uguale a y. Se la risposta è positiva, si procede a controllare che
      esista il nodo left, per richiamare la funzione ricorsivamente, passando k-1 (in quanto uno dei k nodi = y è appena stato
      trovato) e C+1 (per poter scrivere nella cella successiva). In caso tale chiamata ritorni TRUE si imposta la cella corrente
      di C = 0, in quanto abbiamo verificato un nodo sinistro e si ritorna TRUE. In caso la ritorni FALSE, si procede a controllare 
      il nodo destro, se questa chiamata ritorna TRUE si imposta la cella correntedi C = 1, in quanto abbiamo verificato un nodo 
      destro e si ritorna TRUE.
      In caso contrario, si procede a controllare il nodo destro, in caso positivo si imposta la cella corrente di C = 1 e si ritorna TRUE.

      In caso il nodo corrente != y, si eseguono le medesime azioni, soltato che questa volta si passa per riferimento alla funzione chiamata
      ricorsivamente k, in quanto non si è in presenza di un nodo che si sta cercando.

      La chiamata ricorsiva di ogni funzione rispetta la PRE, in quanto albero(r) è ben formato, k>= 0 (casi base 1, 2), y è semrpe invariato e
      non si modifica la dimensione di C, ma soltato i valori delle celle esistenti.

      La chiamata ricorsiva di ogni funzione rispetta la POST, in quanto si ritorna TRUE sse si trova un cammino dalla radice ad una foglia, il
      quale contiene ESATTAMENTE k nodi con campo info uguale a y, in questo caso C contiene, sottoforma di 0(sinistra) e 1(destra), il percorso 
      che porta a tale foglia seguito da -1. Altrimenti ritorna FALSE e C contiene una sequenza vuota.
*/