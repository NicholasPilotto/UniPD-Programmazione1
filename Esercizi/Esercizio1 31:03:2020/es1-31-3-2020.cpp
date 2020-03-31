#include <iostream>
using namespace std;

int &TV(int *p, int lim1, int lim2, int lim3, int f, int n_ele, int n, bool &ok);
int &TH(int *p, int lim1, int lim2, int lim3, int f, int n_ele, int n, bool &ok);

void stampa(int *X, int n_ele, int colonne) {
  int nr = n_ele / colonne, resto = n_ele % colonne;
  for (int i = 0; i < nr; i++) {
    for (int j = 0; j < colonne; j++)
      cout << X[i * colonne + j] << ' ';
    cout << endl;
  }
  for (int i = 0; i < resto; i++)
    cout << X[nr * colonne + i] << ' ';
  cout << endl;
}

int main() {
  int X[100], lim1, lim2, lim3, n_ele;

  cin >> lim1 >> lim2 >> lim3 >> n_ele;

  for (int i = 0; i < n_ele; i++) {
    cin >> X[i];
  }

  bool stop = false, b1 = true, b2 = true;

  while (!stop) {
    int fV, nV, fH, nH;
    cin >> fV;
    if (fV == -1) {
      stop = true;
    } else {
      cin >> nV >> fH >> nH;
      int &y = TV(X, lim1, lim2, lim3, fV, n_ele, nV, b1);

      int &z = TH(X, lim1, lim2, lim3, fH, n_ele, nH, b2);

      if (b1 && b2) {
        int a = y;
        int b = z;
        z = a;
        y = b;
      } else {
        cout << "\noperazione non consentita";
      }
    }
  }
  cout << endl;
  stampa(X, n_ele, lim3);
  return 0;
}

int &TV(int *p, int lim1, int lim2, int lim3, int f, int n_ele, int n, bool &ok) {
  int element = (n / lim2) * (lim2 * lim3) + (n % lim2) * lim3 + f;

  ok = element < n_ele;
  cout << "\nelement colonna " << *(p + element) << endl;
  return *(p + element);
}

int &TH(int *p, int lim1, int lim2, int lim3, int f, int n_ele, int n, bool &ok) {
  int element = (n / lim3) * (lim3 * lim2) + (f * lim3) + (n % lim3);

  cout << "\nelement " << *(p + element) << endl;

  ok = element < n_ele;

  return *(p + element);
}