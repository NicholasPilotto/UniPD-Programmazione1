#include <iostream>

using namespace std;

int main() {
  int n = 0;
  cin >> n;

  int size = n + (n - 3);
  int a = n - 2;
  int b = a;

  if (n < 3) {
    cout << "Altezza non valida" << endl;
  } else {
    for (int j = 0; j < n; j++) {
      if (j == n - 1) {
        a = n - 2;
        b = a;
      }
      for (int i = 0; i < size; i++) {
        if (i < a) {
          cout << "b";
        } else if (i > b) {
          break;
        } else {
          cout << "s";
        }
      }

      a--;
      b++;
      cout << "\n";
    }
  }
  cout << endl;
  return 0;
}