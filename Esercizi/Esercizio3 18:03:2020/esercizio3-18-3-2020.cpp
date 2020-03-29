#include <iostream>
using namespace std;

void superC(int X[][10], int righe, int& sc, int& rip);
bool equalColumn(int a[], int b[]);
void reverseMatrix(int a[10][5], int b[5][10]);

int main() {
  int X[5][10];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> X[i][j];
    }
  }

  int supc = 0;
  int rip = 0;
  superC(X, 5, supc, rip);

  cout << "la super colonna è " << supc << " e ripete " << rip << " volte" << endl;
  return 0;
}

void superC(int X[][10], int righe, int& sc, int& rip) {
  int reverse[10][5];

  bool uguale = false;

  int max = 1;
  reverseMatrix(reverse, X);
  
  for (int i = 0; i < 10; i++) { 
    for (int j = i + 1; j <= 10 - 1; j++) {
      if (equalColumn(reverse[i], reverse[j])) {
        max++;
      }
    }

    if (max > rip) {
      rip = max;
      sc = i;
    }

    max = 1;
  }
}

void reverseMatrix(int a[10][5], int b[5][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      a[i][j] = b[j][i];
    }
  }
}

bool equalColumn(int a[], int b[]) {
  int i = 0;
  bool equal = true;

  while (i < 5 && equal) {
    if (a[i] != b[i]) {
      equal = false;
    }
    i++;
  }

  return equal;
}