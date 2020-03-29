#include <iostream>
using namespace std;

void togliDoppi(int A[], int& dimA);
void spostaInFondo(int A[], int dim);

int main() {
  int A[20], dimA, i = 0;
  cin >> dimA;

  while (i < dimA) {
    cin >> A[i];
    i = i + 1;
    for
  }

  togliDoppi(A, dimA);

  i = 0;
  while (i < dimA) {
    cout << A[i] << ' ';
    i = i + 1;
  }

  cout << endl;
  return 0;
}

// PRE=(A ha dimA elementi, vA=A)
/* R=(0<=i<dimA)&&(0<=j<dimA-1)&&(esaminatio se ci sono doppioni in A[0...dimA])
  1 i = 0 => R
  2 R&&(i < dimA)&&(j < dimA - 1) -> confronto tra A[i] ed A[j...dimA-1]
    - se A[i]==A[j] sposto A[j] nella posizione dimA-j di A poi dimA-- e non incremento j => R
    - se sono diversi i++ => R
  3 R&&(i >= dimA || j >= dimA-1) => POST
*/
void togliDoppi(int A[], int& dimA) {
  int i = 0;
  while (i < dimA) {
    for (int j = i + 1; j < dimA - 1; j++) {
      if (A[j] == A[i]) {
        spostaInFondo(A + j, dimA - j);
        dimA--;
        j--;
      }
    }
    i++;
  }
}
// POST=(in A[0..dimA-1] è prodotto da A togliendo i doppi e mantenendo solo la prima occorrenza di ciascun valore distinto in vA)

// PRE=(A ha dim elementi)
void spostaInFondo(int A[], int dim) {
  for (int i = 0; i < dim; i++) {
    A[i] = A[i + 1];
  }
}
// POST=(il primo elemento di A è stato spostato in posizione dim-1, traslando gli altri elementi di 1 posto a sinistra)
