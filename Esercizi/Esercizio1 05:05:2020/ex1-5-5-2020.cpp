#include <iostream>
using namespace std;

struct nodo {
  int colonna;
  int val;
  nodo* next;
  nodo(int a = 0, int c = 0, nodo* b = 0) {
    colonna = a;
    val = c;
    next = b;
  }
};

void leggi(int* X, int n) {
  for (int i = 0; i < n * n; i++) {
    cin >> X[i];
  }
}

void stampa(nodo* X, int n) {
  if (X) {
    cout << "riga:" << n << " colonna=" << X->colonna << " val=" << X->val << endl;
    stampa(X->next, n + 1);
  }
}

nodo* searchPath(int* X, int r, int c, int n);
int list_sum_values(nodo* a);
void change_values(nodo*& n, int sum);

//! FARE INVARIANTI
int main() {
  int n;
  cin >> n;
  int* B = new int[n * n];
  leggi(B, n);

  nodo* x = 0;
  int max = 0;

  for (int i = 0; i < n; i++) {
    nodo* y = searchPath(B, 0, i, n);

    if (y) {
      int sum = list_sum_values(y);

      if (sum > max) {
        max = sum;

        nodo* a = y;
        change_values(a, sum);

        x = y;
      }
      sum = 0;
    }
  }

  if (!x) {
    cout << "non c'e' cammino" << endl;
  } else {
    stampa(x, 0);
  }
  return 0;
}

// PRE=(X ha n*n valori tutti >=0, 0<=r<=n-1, -1 <=c <= n)
nodo* searchPath(int* X, int r, int c, int n) {
  int sum = 0;
  nodo* tail = 0;

  // PRIMO CASO BASE
  // PRE=(B[0...n-1] definito)
  if (c < 0 || !X[c + (r * n)] || c > n - 1) {
    return NULL;
  }
  // POST=(ritorna NULL sse B[c+(r*n)] è false, oppure c>(n-1) o c<0, questo significa che mi trovo in una colonna non presente in B,
  // quindi la posizione non è valida e sicuramente non ci sarà un elemento del percorso)

  // SECONDO CASO BASE
  // PRE=(0<=r<=n)
  if (r == n - 1) {
    return new nodo(c, X[c + (r * n)]);
  }

  // POST=(ritorno un nuovo nodo della lista contenente il valore della colonna c attuale, trovandomi in una posizione valida ed in una cella contenente un pezzo del percoso,
  // nello specifico la fine di esso. Questo avviene perchè non è stato eseguito il primo caso base)

  // IPOTESI INDUTTIVA
  // la funzione richiama se stessa ricorsivamente nelle righe 72, 75, 77
  // In particolare per i controlli fatti precedentemente si garantisce rispettivamente che:
  //        - 0<=r+1<=n-1
  //        - -1<=c-1<=n && -1<=c<=n && -1<=c+1<=n
  //    => Vale la PRE

  // PASSO INDUTTIVO
  // -> considero che valga la POST delle chiamate ricorsive
  // -> chiamiamo la funzione sulle colonne c-1, c e c+1 fermandoci appena viene identificato un percorso != NULL,
  //        cioè un percorso che ci garantisce di arrivare alla fine
  //        -> se viene identificato tale percorso, allora questo permetterà di raggiungere la riga n-1 dalla riga r+1,
  //            per ottenere il percorso completo basterà aggiungere in testa alla lista la cella attuale
  //        -> se non viene identificato alcun percorso (risultato NULL di tutte le chiamate) allora come richiesto dalla POST
  //            ritorniamo NULL

  tail = searchPath(X, r + 1, c - 1, n);

  if (!tail) {
    tail = searchPath(X, r + 1, c, n);
    if (!tail) {
      tail = searchPath(X, r + 1, c + 1, n);
    }
  }

  if (tail) {
    return new nodo(c, X[c + (r * n)], tail);
  }

  return nullptr;
}
// POST=( se esiste un cammino safe che dalla riga 0 arrivi alla riga n-1, allora la funzione restituisce la lista
// concatenata che rappresenta il cammino a valore massimo con la proprietà spiegata nell’Esempio 2,
// altrimenti, se non esiste alcun cammino safe che attraversi il campo minato, la funzione restituisce 0)

int list_sum_values(nodo* a) {
  int sum = 0;
  while (a) {
    sum += a->val;
    a = a->next;
  }
  return sum;
}

void change_values(nodo*& n, int sum) {
  while (n) {
    int a = n->val;
    n->val = sum;
    sum -= a;
    n = n->next;
  }
}
