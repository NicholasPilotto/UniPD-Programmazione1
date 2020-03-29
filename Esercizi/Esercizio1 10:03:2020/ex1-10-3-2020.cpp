#include <math.h>
#include <iostream>

using namespace std;

void X2B(int x, int B[], int dis);
void Y2B(float y, int B[], int dis);

int main() {
  int X;
  int B[10];
  float Y;
  cin >> X >> Y;
  X2B(X, B, 4);
  Y2B(Y, B + 4, 6);

  for (int i = 0; i < 10; i++) {
    cout << B[i] << ' ';
  }

  cout << endl;

  return 0;
}

void X2B(int x, int B[], int dis) {
  for (int i = dis - 1; i >= 0; i--) {
    if (x % 2 == 0) {
      B[i] = 0;
    } else {
      B[i] = 1;
    }

    x = x / 2;
  }
}

void Y2B(float y, int B[], int dis) {
  int sum = 0;
  float appo;
  for (int i = 0; i < dis; i++) {
    appo = (1 / pow(2, i + 1));
    if ((y - appo) >= 0) {
      B[i] = 1;
      y -= appo;
    } else {
      B[i] = 0;
    }
  }
}