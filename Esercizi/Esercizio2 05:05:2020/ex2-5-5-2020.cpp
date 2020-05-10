#include <iostream>
using namespace std;

//#define nullptr NULL

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

int countDel = 0;
int countNew = 0;

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
      if (!x) {
        x = y;
      } else if (y->val > x->val) {
        x = y;
      }
    }
  }

  if (!x) {
    countNew = 0;
    countDel = 0;
    cout << "non c'e' cammino" << endl;
  } else {
    stampa(x, 0);
    countDel = countNew - 5;
  }
  cout << "nodi creati=" << countNew << " nodi deallocati=" << countDel << endl;
  return 0;
}

//  PRE=(B è un array n*n, a una dimensione) && (0 <= row <= n-1) && (-1 <= col <= n)
//  && (countNew è il numero di nodi allocati (eventualmente già rimossi) nello heap)
//  && (countDel è il numero di nodi deallocati dallo heap)
nodo* searchPath(int* X, int r, int c, int n) {
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;

  if (c < 0 || !X[c + (r * n)] || c > n - 1) {
    return NULL;
  }

  countNew++;
  if (r == n - 1) {
    return new nodo(c, X[c + (r * n)]);
  }

  nodo* tail1 = searchPath(X, r + 1, c - 1, n);
  nodo* tail2 = searchPath(X, r + 1, c, n);
  nodo* tail3 = searchPath(X, r + 1, c + 1, n);

  if (!tail1 && !tail2 && !tail3) {
    return NULL;
  }

  if (tail1) {
    val1 = tail1->val;
  }

  if (tail2) {
    val2 = tail2->val;
  }

  if (tail3) {
    val3 = tail3->val;
  }

  if (val1 >= val2 && val1 >= val3) {
    return new nodo(c, X[c + (r * n)] + val1, tail1);
  } else if (val2 >= val3) {
    return new nodo(c, X[c + (r * n)] + val2, tail2);
  }
  return new nodo(c, X[c + (r * n)] + val3, tail3);
}
// POST=
//    Detto path il cammino più a sx tra i cammini (non contenenti 0) con il valore più alto che collegano B[row][col]
//    all'ultima riga, restituisce una lista in cui ogni nodo contiene il valore di una casella di path,
//    e il valore del sottocammino (che è parte di path) che collega tale cella all'ultima riga,
//    (e il puntatore alla lista del sottocammino da tale cella all'ultima riga)
//
//    Se tale cammino non esiste, restituisce un puntatore nullo.
//
//  && (countNew è il numero di nodi allocati (eventualmente già rimossi) nello heap al termine della funzione)
//  && (countDel è il numero di nodi deallocati dallo heap al termine della funzione)

/*
  CASO BASE:
    - caso in cui la cella non è valida (rifa 76):
      -> se la colonna in cui ci troviamo è < 0 oppure > n - 1, ci troviamo in una cella che non esiste nella matrice
      -> se il valore nella cella è pari a 0, non può esserci un percorso che passa per essa

      => se vengono a verificarsi queste due condizioni, viene restituito un puntatore nullo -> POST

    - caso un cui ci troviamo nell'ultima riga (n - 1) (riga 81):
      -> se non si verifica il primo caso base e ci troviamo nell'ultima riga disponibile della matrice,
         significa che la cella in cui ci troviamo è una cella valida del percorso
         => se si verifica questo caso base, viene ritornato un nuovo nodo con la colonna corrente e il valore della cella in cui ci troviamo -> POST
      
      Il cammino che viene ritornato è quello più a sinistra e quello con il valore più alto tra i cammini validi che collegano il fondo con la cella di partenza
      della prima riga della matrice

  CASO INDUTTIVO:
    La cella è valida e non è nell'ultima riga, quindi (0 <= col <= n-1) && (0 <= row <= n-2). Si invoca tre volte la funzione searchPath su elementi col-1,col,col+1 di riga n+1
    (in tutti e tre i casi l'invocazione è legale perché (0 <= col <= n-1) && (0 <= row <= n-2) garantisce la validità di PRE in col-1,col,col+1 di riga successiva).

    L'IPOTESI INDUTTIVA afferma che OGNI INVOCAZIONE RICORSIVA searchPath(B, row + 1, col - 1, n), searchPath(B, row + 1, col, n), searchPath(B, row + 1, col + 1, n), di righe 85, 86, 87,
    rispetta la POST con le dovute modifiche ai parametri, ovvero RISOLVE UN'ISTANZA PIÙ PICCOLA DEL PROBLEMA.

    In particolare l'ipotesi induttiva coincide con la POST di ogni invocazione ricorsiva, e garantisce che ogni invocazione ricorsiva (su una cella "figlia" di B[c + (r * n)])
    ritorna (se esiste) la lista associata al cammino più a sinistra tra quelli di valore massimo che collegano il "figlio" di B[c + (r * n)] al fondo.

    Per ritornare la lista corretta bisogna anzitutto individuare la lista più a sinistra tra quelle con valore più alto
    per ciascuno dei tre figli e di queste selezionarne una (se ne esiste almeno una):

    Si invoca searchPath su elementi col-1 di riga n+1, col e riga + 1, col + 1 e riga + 1

    Si controlla che i nodi ritornati da tali chiamate siano valori non validi, se così fosse viene ritoranto un puntatore nullo.
    Un ulteriore controllo viene fatto per controllare i valori dei singoloìi nodi ritoranti dalle chiamate ricorsive. Se essi sono valori validi, essi vengono allocati nella corrispettava
    variabile val_i (con 1<=i<=3).
    Per trovare il persorso più a sinistra, si controlla quale dei tre valori è il maggiore e, quando esso è stato trovato tra i tre valori, viene ritornato il nodo contenente la colonna corrente, 
    il valore della cella corrente sommato a val_i (con val_i il valore del percorso a sinistra con valore maggiore)
*/
