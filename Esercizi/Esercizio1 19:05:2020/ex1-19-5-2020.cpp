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

nodo* match(nodo*& T, nodo* P);
bool cont(nodo* T, nodo* P);

void stampa(nodo* L) {
  if (L) {
    cout << L->info << ' ';
    stampa(L->next);
  }

  else
    cout << endl;
}

int main() {
  int m, n;
  cin >> m >> n;
  nodo* T = faiL(m);
  nodo* P = faiL(n);
  P = match(T, P);
  stampa(P);
  stampa(T);
  return 0;
}

// PRE=(L(T) e L(P) sono ben formate)
nodo* match(nodo*& T, nodo* P) {
  if (!T) {
    return NULL;
  }
  if (T->info == P->info) {
    if (T->next && P->next) {
      bool ok = cont(T->next, P->next);
      if (ok) {
        nodo* x = T;
        nodo* y = P;

        while (P) {
          x = x->next;
          P = P->next;
        }

        T = x;
        return y;
      }
    }
  } else {
    return match(T->next, P);
  }
}
// POST=(se in T c’è un match di P contiguo e completo, allora la funzione estrae i nodi del match più a sinistra e la restituisce col return
// mentre T è la lista che resta, se non c’è match la funzione restituisce 0 e L(T) non cambia)

/*
  CASO BASE1: è stata passata tutta la lista T (riga 49):
    - se il nodo T in cui ci troviamo è NULL, significa che ci troviamo nel nodo puntato (NULL) dall'ultimo nodo valido della lista T. Se questo
      controllo ritorna come risultato TRUE significa che tutta la lista T è stata controllata e non vi è un match completo di P in T.

  CASO BASE2: campi info di T e P dei nodi correnti sono uguali (riga 52):
    - se i valori info dei nodi correnti delle rispettive liste T e P sono uguali, questo vuol dire che il nodo corrente potrebbe essere l'inizio di un
      match completo di P in T. Per verificare questo, utilizziamo una funzione ausiliare cont, la quale ritorna TRUE sse vi è un match contiguo di P in T,
      a partire dal nodo successivo a quello in cui ci troviamo al momento dell'invocazione, questo perché il primo nodo del possibile match è già stato 
      controllato da questo caso base. Nel caso cont ritornasse un valore TRUE, quindi siamo in presenza di un match, vengono create due variabili di appoggio
      per il salvataggio dell'indirizzo corrente di T e P. T viene passata, eliminando i nodi che creano il match. Viene ritornato con il return il primo indirizzo
      della lista contenente i nodi del match

  PASSO INDUTTIVO (riga 69):
    - arrivati a questo punto sappiamo che la lista T fino ad ora non contiene match e che il nodo corrente è valido, quindi (T)&&(T->info != P->info).
      In questo punto del programma si provvede a richiamare ricorsivamente la funzione match, passando per riferimento il nodo successivo al corrente della
      lista T, e per valore il nodo corrente della lista P. Questa operazione è valida, dato che il nodo corrente non è nullo -> CASO BASE1.

      L'ipotesi induttiva rispetta la PRE di ogni invocazione ricorsiva, in quanto sia vL(T)@L(T) e L(P) sono ben formate e rispetta la POST di ogni invocazione
      ricorsiva in quanto garantisce che ad ogni chiamata, in presenza del match contiguo più a sinistra di P in T, estrai tali nodi che formano il match da T e, tramite return
      restituisce una lista con tali nodi, mentre se non vi è nessun match contiguo, ritorna NULL (0)
*/

//PRE=(L(T) e L(P) sono ben formate)
bool cont(nodo* T, nodo* P) {
  if (!P) {
    return true;
  }
  if (!T) {
    return false;
  }

  if (T->info == P->info) {
    return cont(T->next, P->next);
  } else {
    return false;
  }
}
//POST=(ritorna TRUE sse vi è un match completo e contiguo di P in T)