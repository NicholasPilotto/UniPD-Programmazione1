#include <iostream>

using namespace std;

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

nodo* insOrd_ric(nodo* L, nodo* x);
nodo* insOrd_iter(nodo* L, nodo* x);

int main() {
  int m, x;
  cin >> m >> x;
  nodo* L = faiL(m);
  nodo* L1 = clone(L);

  L = insOrd_ric(L, new nodo(x));
  L1 = insOrd_iter(L1, new nodo(x));
  stampa(L);
  stampa(L1);
  return 0;
}

// PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo* insOrd_ric(nodo* L, nodo* x) {
  if (!x->info) {
    x->next = L;
    return x;
  }
  if (!L) {
    return new nodo(x->info);
  }
  if (L->info > x->info) {
    return new nodo(x->info, L);
  } else {
    L->next = insOrd_ric(L->next, x);
  }
  return L;
}
// POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)
/*
  CASO BASE1: il valore del campo info di x == 0 (riga55):
    - se il valore del campo info di x è 0, il nodo deve essere inserito in prima posizione, quindi si ritorna
      x@Lista(L)

  CASO BASE2: La lista è vuota (riga 59):
    - se il nodo L è non valido (NULL) significa che la lista è o vuota, quindi x sarà il primo nodo di essa, oppure,
      caso opposto, è stata passata tutta la lista e i valori contenuti sono tutti minori del campo info di x, quindi
      x andrà alla fine, la funzione ritorna Lista(L)@x

  CASO BASE3: il nodo corrente di Lista(L) ha campo info minore di x (riga 62):
    - se il nodo corrente di Lista(L) ha campo info minore di x, il nodo x deve essere inserito in questa posizione,
      traslando di un posto i nodi dal corrente fino all'ultimo di Lista(L). Per fare ciò si ritorna un nuovo nodo
      con campo info uguale a campo info di x e campo next il resto della Lista(L), quindi: vLista(L)@x@resto

  CASO RICORSIVO: campo info di x maggiore del campo info del nodo corrente (riga 64):
    - se ci troviamo in questo punto, significa che Lista(L) non è vuota o la sua fine, campo info di x è maggiore del
      campo info dei nodi precedenti, quindi si deve controllare ricorsivamente il resto della lista. Per fare ciò richiamiamo,
      appunto, ricorsivamente la funzione insOrd_ric, passando il nodo successivo al seguente ed il nodo da inserire x, entrambi per valore.

      Tale operazione rispetta la PRE di ogni chiamata ricorsiva, in quanto x punta ad un nodo, non essendo mai stato modificato, e L è ben formata,
      questo ce lo assicura CASO BASE1.
      Rispetta anche la POST di ogni chiamata ricorsiva, in quanto la funzione, nel caso trovasse un campo info più piccolo di x nella lista, inserirebbe x
      in questa posizione, altrimenti in testa o in coda alla lista, in base se la lista è vuota o già ordinata. Quindi, riassumendo, la funzione restituisce
      una vL(L)@x in modo tale che vL(L) abbia i campi info disposti ordinatamente in ordine crescente
*/

// PRE=(Lista(L) ben formata e ordinata, x punta ad un nodo)
nodo* insOrd_iter(nodo* L, nodo* x) {
  nodo* s = L;
  if (!L) {
    return new nodo(x->info);
  }
  if (x->info == 0) {
    return new nodo(x->info, L);
  }
  // R=(L->next)&&(x->info > L->next->info)
  // 1) L->next -> essendo la lista ben formata ed avendo effettuato il controllo che la lista contenga almeno un nodo, la prima iterazione entra nel ciclo
  //    x->info > L->next->info -> avendo già controllato se il campo info di x fosse 0, x inizialmente non sarà più piccola del secondo nodo
  //    => R
  // 2) L->next -> in quanto L è ben formata, quindi punta ad un altro nodo
  //    x->info < L->next->info -> in quanto la lista è ordinata
  //    => R
  // 3) !L->next -> significa che è stata passata tutta la lista e nessuno dei campi info era minore del campo info di x, quindi x viene inserito alla fine
  //    x->info < L->next->info -> il campo info di x è minore del successivo, quindi x va inserita in questa posizione
  //    => POST
  while (L->next && x->info > L->next->info) {
    L = L->next;
  }
  x->next = L->next;
  L->next = x;
  return s;
}
// POST=(restituisce vL(L) con x aggiunto in modo che la nuova lista sia ancora ordinata)