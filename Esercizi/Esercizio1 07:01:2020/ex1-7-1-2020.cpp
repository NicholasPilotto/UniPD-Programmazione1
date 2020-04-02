#include <iostream>

using namespace std;

void leggi(int A[], int dim);

int main() {
  int A[100];
  int P[20];
  int dimA;
  int dimP;
  cin >> dimA >> dimP;
  leggi(A, dimA);
  leggi(P, dimP);

  int cont = 0;
  for (int i = 0; i < dimA; i++) {
    if (A[i] == P[cont]) {
      cont++;
    } else {
        i -= cont;
        cont = 0;
    } 
    if (cont == dimP) {
      cout << "trovato match che inizia in posizione " << i - cont + 1 << " di A\n";
    }
  }

  return 0;
}

void leggi(int A[], int dim) {
  int i = 0;
  while (i < dim) {
    cin >> A[i];
    i = i + 1;
  }
}

