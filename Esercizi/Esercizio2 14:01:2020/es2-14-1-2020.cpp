#include <iostream>
using namespace std;

void leggi(int A[], int dim) {
  int i = 0;
  while (i < dim) {
    cin >> A[i];
    i = i + 1;
  }
}

int trovaCrescente(int a[], int dim);

int main() {
  int A[100], dimA;
  int lungmax = 0;
  int inizio = -1;  // inizio=-1 segnala che non si è trovato ancora alcun SC
  cin >> dimA;
  leggi(A, dimA);
  int scorriA = 0;

  bool stop = false;

  while (scorriA <= dimA - 1 && !stop) {
    int lung = trovaCrescente(A + scorriA, dimA - scorriA);

    if (lung == -1) {
      stop = true;
    } else {
      if (lung > lungmax) {
        lungmax = lung;
        inizio = scorriA;
      }
    }

    scorriA++;
  }

  cout << "il più lungo SC inizia in " << inizio << " e ha lunghezza "
       << lungmax << endl;
  return 0;
}

int trovaCrescente(int a[], int dim) {
  bool exit = false;
  int lung = 0;
  int i = 0;

  while (i < dim - 1 && !exit) {
    if (a[i] <= a[i + 1]) {
      lung++;
    } else {
      exit = true;
    }
    i++;
  }

  return ++lung;
}

