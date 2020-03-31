#include <iostream>
using namespace std;

int S(int *A, int n);

int main() {
  int X[400];
  cin >> X[0];
  for (int i = 1; i < 400 && X[i - 1] != -2; i++) {
    cin >> X[i];
  }

  int n;
  cin >> n;
  cout << "start" << endl;
  int b = S(X, n);  // da fare
  if (b == -2) {
    cout << "sottosequenza " << n << " non presente" << endl;
  } else {
    cout << "inizio sottosequenza " << n << " indice=" << b << endl;
  }
  cout << "end" << endl;

  return 0;
}

int S(int *A, int n) {
  int i = 0;
  int subSequence = 0;
  if (A[0] != -2) {
    while (true) {
      if (A[i] == -1) {
        subSequence++;
        if (subSequence == n) {
          if (A[i + 1] != -2) {
            return i + 1;
          } else {
            return -2;
          }
        }
      }
      i++;
    }
  }

  if (subSequence < n) {
    return -2;
  }

  return -2;
}