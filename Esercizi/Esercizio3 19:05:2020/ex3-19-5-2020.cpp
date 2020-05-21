#include <iostream>

using namespace std;

// #define nullptr NULL

struct nodo {
  int info;
  nodo* next;
  nodo(int a = 0, nodo* b = 0) {
    info = a;
    next = b;
  }
};

nodo* faiL(int n) {
  if (n) {
    int x;
    cin >> x;
    return new nodo(x, faiL(n - 1));
  }
  return 0;
}

void stampa(nodo* L) {
  if (L) {
    cout << L->info << ' ';
    stampa(L->next);
  } else {
    cout << endl;
  }
}
nodo* clone(nodo* L) {
  if (L) {
    return new nodo(L->info, clone(L->next));
  }
  return 0;
}

nodo* ord_ric(nodo* L);
nodo* insOrd_ric(nodo* L, nodo* x);
// --------------------------------- //
nodo* ord_iter(nodo* L);

int main() {
  int m;
  cin >> m;
  nodo* L = faiL(m);
  nodo* P = clone(L);

  L = ord_ric(L);
  P = ord_iter(P);
  stampa(L);
  stampa(P);

  return 0;
}

// PRE=(L(L) è ben formata)
nodo* ord_ric(nodo* L) {
  if (!L) {
    return nullptr;
  }

  nodo* x = ord_ric(L->next);
  nodo* a = insOrd_ric(x, L);
  return a;
}
// POST=(restituisce una lista ordinata composta con tutti i nodi di L(n))
/*
  CASO BASE: la lista è vuota (riga 61):
    - questo caso base si occupa di trattare il caso in cui il nodo corrente sia NULL, ovvero
      ci troviamo in una lista vuota, oppure abbiamo passato tutta la lista, quindi ci troviamo
      nel nodo successivo all'ultimo, che, appunto, ci identifica la fine della lista.
      Banalmente, se ci troviamo in questo caso, la funzione ritorna un puntatore nullo

  CASO RICORSIVO (riga 65):
    - se ci troviamo in questo caso, sappiamo che L(L) non è vuota, il nodo in cui ci troviamo è un nodo
      valido (non NULL), quindi possiamo procedere a richiamare la funzione ricorsiva nel nodo successivo
      al corrente.

      La chiamata ricorsiva rispetta la PRE di ogni chiamata ricorsiva, in quanto garantisce, dal caso base,
      che L(L) è ben formata.
      La chiamata ricorsiva rispetta la POST di ogni chiamata ricorsiva, in quanto garantisce, dal caso base,
      in quanto la funzione, richiamando la funzione ausiliaria ord_ric, la quale garantische di ritornare una
      lista ordinata composta, senza eliminare alcun nodo, crea una lista di supporto, dove nella quale, ad ogni
      chiamata, aggiunge e posiziona correttamente, tutti i nodi di L(L)

      Per completezza:
      PRE=(L(L) è ben formata)
      nodo* ord_iter(nodo* L) {
      POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)
*/

// PRE=(L(L) è ben formata)
nodo* ord_iter(nodo* L) {
  nodo* a = nullptr;
  nodo* x = L;
  while (L) {
    a = insOrd_ric(a, L);
    L = L->next;
  }
  return a;
}
// POST=(restituisce una lista ordinata composta con tutti i nodi di L(n))

// PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo* insOrd_ric(nodo* L, nodo* x) {
  if (!x->info) {
    x->next = L;
    return x;
  }
  if (!L) {
    return new nodo(x->info);
  }
  if (L->info >= x->info) {
    return new nodo(x->info, L);
  } else {
    L->next = insOrd_ric(L->next, x);
  }
  return L;
}
// POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)