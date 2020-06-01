#include <iostream>

using namespace std;

// #define nullptr NULL

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

int stampaASPre(nodo* r, int n, int k);
int stampaASInf(nodo* r, int n, int k);

int main() {
  int dim;
  cin >> dim;
  int* a = new int[dim];
  for (int i = 0; i < dim; i++) {
    cin >> a[i];
  }

  nodo* root = NULL;
  root = buildTree(a, 0, dim);
  //stampa_l(root);

  int k;
  cin >> k;

  int a1 = stampaASPre(root, k - 1, k);
  cout << " con avanzo " << a1 << endl;
  int b1 = stampaASInf(root, k - 1, k);
  cout << " con avanzo " << b1 << endl;
  return 0;
}

// PRE=(albero(r) ben formato,0<= n<=k, k>0)
int stampaASPre(nodo* r, int n, int k) {
  if (!r) {
    return n;
  }

  if (!n) {
    cout << r->info << ' ';
    n = k;
  }

  n--;
  n = stampaASPre(r->left, n, k);
  n = stampaASPre(r->right, n, k);
  return n;
}
// POST=(considerando I nodi di albero® in ordine prefisso, salta n nodi e poi stampa quello successivo
// e dopo ne salta k-1 e poi stampa il successivo, restituisce il numero di nodi che vanno saltati nelle
// successive parti dell’albero)
/*
  CASO BASE1: albero vuoto (riga 84):
    - se ci troviamo in questo caso, l'albero è vuoto, quindi si ritorna attraverso return il valore di n

  CASO BASE2: n == 0 (riga 88):
    - se ci troviamo in questo caso base significa che sono stato passati k-1 nodi, quindi il corrente,
      il k-esimo nodo nella sequenza, deve essere stampato. n viene posto uguale a k per ricominciare la
      sequenza di nodi da "saltare"
  
  CASO RICORSIVO: riga 93:
    - se ci troviamo in questo caso significa che dobbiamo decrementare n, dato che abbiamo viistato un nuovo nodo,
      il corrente, e ricorsivamente invochiamo la funzione sul nodo sinistro e poi destro, passando per valore 
      il corrente n e k costante

      La chiamata ricorsiva di ogni funzione rispetta la PRE, infatti da CASO BASE1 sappiamo che l'albero corrente
      non è vuoto e da CASO BASE2 0 < n <= k

      La chiamata ricorsiva di ogni funzione rispetta la POST, infatti la funzione richimando ricorsivamente se stessa
      sui sottoalberi sinistro e poi destro di ogni nodo e stampando il k-esimo nodo prima di richiamarsi ricorsivamente
      stamperà altezza(r) / k nodi in ordine prefisso, ritornando con il return il valore di n, variabile contentente il
      numero di nodi da "saltare", quindi il resto di albero(r)
*/

// PRE=(albero(r) ben formato,0<= n<=k, k>0)
int stampaASInf(nodo* r, int n, int k) {
  if (!r) {
    return n;
  }

  n = stampaASInf(r->left, n, k);
  if (!n) {
    cout << r->info << ' ';
    n = k;
  }

  n--;
  n = stampaASInf(r->right, n, k);
  return n;
}
// POST=(considerando I nodi di albero® in ordine infisso, salta n nodi e poi stampa quello successivo
// e dopo ne salta k-1 e poi stampa il successivo, restituisce il numero di nodi che vanno saltati nelle
// successive parti dell’albero)