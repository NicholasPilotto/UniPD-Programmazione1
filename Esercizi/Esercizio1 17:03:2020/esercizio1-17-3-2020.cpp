#include <iostream>
using namespace std;

void elimina(int A[], int& dimA, int fetta);

int main() {
  int A[20];
  int dimA;
  int fetta;
  int i = 0;
  cin >> dimA;

  while (i < dimA) {
    cin >> A[i];
    i++;
  }

  cin >> fetta;
  elimina(A, dimA, fetta);

  i = 0;
  while (i < dimA) {
    cout << A[i] << ' ';
    i++;
  }

  cout << endl;
  return 0;
}

// PRE=(A contiene dimA elementi, dimA>=0, A=vA)
/*
 R=(0<=i<dimA)&&(esaminato se in A[0...dimA] sono presenti valori uguali a fetta)
 1 i = 0 => R
 2 R&&(i < dimA) -> confronto A[i] con fetta
    - se sono uguali sposto A[i] nella posizione dimA-i di A poi dimA-- => R
    - se sono diversi i++ => R
 3 R&&(i >= dimA) => POST
*/
void elimina(int A[], int& dimA, int fetta) {
  int i = 0;
  while (i < dimA) {
    if (A[i] == fetta) {
      for (int j = i; j < dimA - i; j++) {
        A[j] = A[j + 1];
      }
      dimA--;
    } else {
      i++;
    }
  }
}
// POST=(A[0..dimA-1] contiene gli elementi di vA diversi da fetta nell’ordine relativo che essi avevano in vA)

// void elimina(int A[], int& dimA, int fetta) {
//   int* p = A;
//   int i = 0;
//   while (i < dimA) {
//     cout << "sono qui " << p[i] << endl;
//     if (p[i] == fetta) {
//       int* a;
//       if (i > 0) {
//         a = &p[--i];
//         cout << "a " << a << endl;
//         cout << "p " << p << endl;
//         cout << "p+1 " << &p[i + 1] << endl;
//         a = (int*)&p[i + 1];
//         cout << "a " << a << endl;
//       } else {
//         a = &p[i];
//         *a = p[i + 1];
//       }
//       dimA--;
//     }  //else {
//     i++;
//     // }
//   }
// }