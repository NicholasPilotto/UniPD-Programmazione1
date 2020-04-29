#include <iostream>
using namespace std;
struct nodo {
  int colonna;
  nodo* next;
  nodo(int a = 0, nodo* b = 0) {
    colonna = a;
    next = b;
  }
};

void leggi(bool* X, int n) {
  for (int i = 0; i < n * n; i++) {
    cin >> X[i];
  }
}

void stampa(nodo* X, int n) {
  if (X) {
    cout << "riga:" << n << " colonna=" << X->colonna << endl;
    stampa(X->next, n + 1);
  }
}

nodo* searchPath(bool* B, int r, int c, int n);

int main() {
  int n;
  cin >> n;
  bool* B = new bool[n * n];
  leggi(B, n);

  nodo* x = 0;

  for (int i = 0; i < n && !x; i++) {
    x = searchPath(B, 0, i, n);
  }

  if (!x) {
    cout << "non c'e' cammino" << endl;
  } else {
    stampa(x, 0);
  }

  delete[] B;
  return 0;
}

// PRE=(B va visto come un array di bool[n][n], 0<=r<=n-1, -1<=c<=n)
nodo* searchPath(bool* B, int r, int c, int n) {
  nodo* tail = 0;
  nodo* appo = 0;

  // PRIMO CASO BASE
  // PRE=(B[0...n-1] definito)
  if (c < 0 || !B[c + (r * n)] || c > n - 1) {  // caso base
    return NULL;
  }
  // POST=(ritorna NULL sse B[c+(r*n)] è false, oppure c>(n-1) o c<0, questo significa che mi trovo in una colonna non presente in B,
  // quindi la posizione non è valida e sicuramente non ci sarà un elemento del percorso)

  // SECONDO CASO BASE
  // PRE=(0<=r<=n)
  if (r == n - 1) {
    return new nodo(c);
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

  tail = searchPath(B, r + 1, c - 1, n);

  if (!tail) {
    tail = searchPath(B, r + 1, c, n);
    if (!tail) {
      tail = searchPath(B, r + 1, c + 1, n);
    }
  }

  if (tail) {
    return new nodo(c, tail);
  }
  return NULL;
}
// POST=(se c’è un cammino dalla posizione c della riga r fino alla riga n-1,
// allora la funzione restituisce una lista concatenata i cui nodi contengono nel loro campo colonna le colonne del cammino più a sinistra che dalla riga i,
// colonna c, arriva fino alla riga n-1, se non c’è un tale cammino allora la funzione restituisce 0)
