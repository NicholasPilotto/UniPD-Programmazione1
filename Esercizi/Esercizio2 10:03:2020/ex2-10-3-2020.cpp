#include <math.h>
#include <iostream>

using namespace std;

int f1(int B[], int dis);
float f2(int B[], int dis);

int main() {
  int B[10];

  for (int i = 0; i < 10; i++) {
    cin >> B[i];
  }

  int pi = f1(B, 4);
  float pdec = f2(B + 4, 6);

  cout << "value=" << pi + pdec << endl;
  return 0;
}

int f1(int B[], int dis) {
  int sum = 0;
  for (int i = dis; i >= 0; i--) {
    if (B[i] != 0) {
      sum += pow(2, (dis - (i + 1)));
    }
  }

  return sum;
}

float f2(int B[], int dis) {
  float sum = 0;

  for (int i = 0; i < dis; i++) {
    if (B[i] != 0) {
      sum += (1 / pow(2, i + 1));
    }
  }

  return sum;
}
