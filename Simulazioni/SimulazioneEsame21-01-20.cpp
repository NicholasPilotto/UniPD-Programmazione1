#include <iostream>
using namespace std;

void leggi(int A[], int dim) {
  int i = 0;
  while (i < dim) {
    cin >> A[i];
    i = i + 1;
  }
}

// dichiarazione della funzione cercaMatch
bool cercaMatch(int a[], int b[], int dimB);

/*
* PRE=(dati in input 2 array e le loro dimensioni, le quali possono essere valori di non uguale grandezza,
* verificare se nell'array A e' presente un match dell'array B, con la possibilita' che ci sia un valore non
* presente nel match)
*/

int main() {
  // inizializzazione variabili
  int A[100], P[20], dimA, dimP;
  cin >> dimA >> dimP;
  leggi(A, dimA);
  leggi(P, dimP);
  int scorriA = 0;
  bool trovato = false;

  /*
  *  R=(0 <= scorriA < dimA - dimP + 1)
  *  1) letti i valori e inseriti nel primo array
  *  2) letti i valori e inseriti nel secondo array
  *  3) controllo se in una porzione del primo array si verifica un match con il secondo array tramite il metodo 'cercaMatch'
  *  4) match=false => scorriA++
  *  5) match=true => trovato=true, stampa in output la posizione di partenza del match, scorriA+dimP
  *  6) trovato=false => stampa in output che non è presente nessun match in quel settore
  */

  while /*R*/ (scorriA < dimA - dimP + 1) {
    bool match = cercaMatch(A + scorriA, P, dimP);

    if (!match) {
      scorriA++;
    } else {
      trovato = true;
      cout << "match a partire dalla posizione " << scorriA << " di A" << endl;
      scorriA += dimP;
    }
  }

  if (!trovato) {
    cout << "nessun match trovato" << endl;
  }

  return 0;
}

/*
*  POST=(trovati i match non sovrapposti di P in A (con 1 errore al massimo) e fatte le stampe richieste) && (se non c’è alcun match viene stampato “nessun match trovato”)
*/

/* ------ TROVAMATCH ------ */

/*
* PRE=(vengono passati in input due array e la dimensione del secondo vettore, la quale verrà utilizzato come valore sentinella)
*/

bool cercaMatch(int a[], int b[], int dimB) {
  bool errore = false;
  bool exit = false;
  int i = 0;

  /*
  *  R=(0 <= dimB && !exit)
  *  1) a[i]!=b[i] => e' un errore
  *  2) errore=false => errore=true
  *  3) errore=true => exit=true
  *  4) i+1
  */

  while /* R */ (i < dimB && !exit) {
    if (a[i] != b[i]) {
      if (!errore) {
        errore = true;
      } else {
        exit = true;
      }
    }

    i++;
  }

  return !exit;
}

/*
* POST=(controllata una porzione di grandezza dimB dell'arrayA, viene ritornato un valore booleano che indica la presenza o meno di un match (con 1 errore consentito))
*/
