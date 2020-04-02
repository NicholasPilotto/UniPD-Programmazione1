#include <iostream>
using namespace std;

void leggi(int A[], int dim) {
  int i = 0;
  while (i < dim) {
    cin >> A[i];
    i = i + 1;
  }
}

main() {
  int A[100], P[20], dimA, dimP, lungmax = 0, inizio = 0;
  cin >> dimA >> dimP;
  leggi(A, dimA);
  leggi(P, dimP);

  int cont = 0;
  for (int i = 0; i < dimA; i++) {
    if (A[i] == P[cont]) {
      cont++;
    } else {
      if (cont > lungmax) {
          lungmax = cont;
          inizio = i - cont;
      }
       i -= cont;
       cont = 0;
    }
   
  }
  cout << "il massimo match ha lunghezza " << lungmax << " e inizia in posizione "
     << inizio << " di A" << endl;
}
