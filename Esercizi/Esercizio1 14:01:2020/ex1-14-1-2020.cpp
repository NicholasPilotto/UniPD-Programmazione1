#include <iostream>
using namespace std;

void leggi(int A[], int dim) {
  int i = 0;
  while (i < dim) {
    cin >> A[i];
    i = i + 1;
  }
}

int trovaPattern(int a[], int b[], int dim1, int dim2);

int main() {
  int A[100], P[20], dimA, dimP;

  cin >> dimA >> dimP;
  leggi(A, dimA);
  leggi(P, dimP);
  int scorriA = 0;

  int lungmin = -1;
  int inizio = 0;
  bool stop = false;

  while (scorriA < dimA - dimP + 1) {
    int appo = trovaPattern(A + scorriA, P, dimA - scorriA, dimP);

    if (appo != -1) {
      if (lungmin == -1 || appo < lungmin) {
        lungmin = appo;
        inizio = scorriA;
      }
    }

    scorriA++;
  }

  if (lungmin == -1) {
    cout << " nessun match trovato" << endl;
  } else {
    cout << "il miglior match inizia in " << inizio << " e ha larghezza "
         << lungmin << endl;
  }

  return 0;
}

int trovaPattern(int a[], int b[], int dim1, int dim2) {
  bool exit = false;
  int i = 0;
  int j = 0;

  while (i < dim1 && !exit) {
    if (a[i] == b[j]) {
      j++;
    }

    if (j == dim2) {
      exit = true;
      return i += 1;
    }

    i++;
  }

  return -1;
}
