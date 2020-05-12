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
nodo* elimOne(nodo* L, int x);
void elimOne2(nodo* L, int x);
void elimOne3(nodo*& L, int x);

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
  }

  else {
    cout << endl;
  }
}

nodo* clone(nodo* L) {
  if (L) {
    return new nodo(L->info, clone(L->next));
  }
  return 0;
}

int main() {
  int m, x;
  cin >> m >> x;
  nodo* L = faiL(m);
  //stampa(L);

  nodo *L2, *L3;
  L2 = clone(L);
  if (L2->info == x) {
    L2 = new nodo(x + 1, L2);
  }
  L3 = clone(L);

  L = elimOne(L, x);
  if (L2) {
    elimOne2(L2, x);
  }

  if (L3) {
    elimOne3(L3, x);
  }
  stampa(L);
  stampa(L2);
  stampa(L3);

  return 0;
}

// PRE=(Lista(L) ben formata, vL(n) = L(n))
nodo* elimOne(nodo* L, int x) {
  if (!L) {
    return NULL;
  }
  if (L->info == x) {
    nodo* appo = L->next;
    delete L;
    return appo;
  }
  L->next = elimOne(L->next, x);
  return L;
}
// POST=(restituisce una lista che contiene tutti i nodi di Lista(L) a parte il primo con info=x, che, se esiste, va anche deallocato)

// PRE=(Lista(L) ben formata e non vuota e col primo nodo tale che il suo campo info non sia x, vLista(L)=Lista(L))
void elimOne2(nodo* L, int x) {
  if (L->next) {
    if (L->next->info == x) {
      nodo* appo = L->next->next;
      delete L->next;
      L->next = appo;
    } else {
      elimOne2(L->next, x);
    }
  }
}
/*
  CASI BASE:
    Ultimo elemento della lista (riga 88):
      se L->next è false, significa che ci troviamo o nel primo nodo ed il secondo non esiste, quindi la dimensione della lista è 1,
      oppure ci troviamo nel penultimo nodo
        => sicuramente il campo info delnodo successivo non sarà uguale ad x, essendo questo nullo
    
    Campo info del nodo successivo == x (riga 89):
      se il caso precendente non si verifica ed il campo info del nodo successivo al corrente == x, viene allocato un nuovo nodo di nome appo,
      il quale punterà a due nodi successivi al nodo in cui ci troviamo, questo per creare una variabile di supporto, per memorizzare l'indirizzo
      del nodo successivo a quello che si andrà a deallocare, ovvero il pirmo nodo della lista con il campo info == x. Fatto ciò si collega
      il resto della lista con il nodo corrente, creando vL(L)@l(L->next->next)
      
  PASSO INDUTTIVO:
    arrivati a questo punto, sappiamo che esiste e non è nullo il nodo successivo al corrente, il campo info di questo non corrisponde ad x, quindi 
    (L->next)&&(!L->next->info). Quindi si provede ad invocare la funzione elimOne2 ricorsivamente. Questa operazione è valida, dato che L->next è un
    nodo esistene e non nullo (la certezza di ciò è data dai casi base).
    
    L'ipotesi induttiva rispetta la POST di ogni invocazione ricorsiva, in quanto garantisce che ad ogni invocazione ricorsiva, Lista(L) contiene tutti
    nodi di vLista(L)tranne, eventualemnte, il primo nodo con il campo info == x.

    Il fatto che ci garantisce che la lista abbia almeno 1 nod0, è la chiamata effettuata dal chiamante iniziale (main in questo caso), il quale, prima
    di richiamare la primva volta la funzione elimOne2, verifica che, appunto, verifica l'esistenza di questo.
*/
// POST=(Lista(L) contiene tutti i nodi di vLista(L) a parte il primo con info=x, che, se esiste, va anche deallocato)

// PRE=(Lista(L) ben formata e VLista(L)=Lista(L))
void elimOne3(nodo*& L, int x) {
  if (L) {
    if (L->info == x) {
      delete L;
      L = L->next;
    } else {
      elimOne3(L->next, x);
    }
  }
}
//POST=(Lista(L) è come vLista(L) a parte il primo nodo con info=x, che, se esiste, va anche deallocato)