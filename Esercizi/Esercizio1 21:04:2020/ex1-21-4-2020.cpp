#include <iostream>
using namespace std;

int& f(int* x, int lim1, int lim2, int lim3, int nele, int fex, int n);

int main() {
  int X[400] = {};
  int lim1, lim2, lim3;
  int nele;
  cin >> lim1 >> lim2 >> lim3 >> nele;
  int nfvp = nele / (lim1 * lim2);   //strati pieni VFetta
  int resto = nele % (lim1 * lim2);  //elementi ultimo strato

  for (int i = 0; i < nfvp; i++) {
    for (int r = 0; r < lim2 * lim1; r++) {
      cin >> X[i + r * lim3];
    }
  }

  for (int r = 0; r < resto; r++) {
    cin >> X[nfvp + r * lim3];
  }

  bool avanti = true;
  while (avanti) {
    int fex, n;
    cin >> fex;
    if (fex == -1)
      avanti = false;
    else {
      try {
        cin >> n;
        int& y = f(X, lim1, lim2, lim3, nele, fex, n);
        if (y > nele) {
          throw(y);
        } else {
          cout << "elemento n." << n << " della H-fetta " << fex << " e' =" << y << endl;
        }
      } catch (int x) {
        cout << "elemento non esiste" << endl;
      }
    }
  }
  return 0;
}
// PRE=(x ha lim1*lim2*lim3 elementi e ha nele valori definiti e inseriti per V-fette, 0<=fex < lim3, n>=0)
int& f(int* x, int lim1, int lim2, int lim3, int nele, int fex, int n) {
  int exit = false;
  int num = -1;
  int appo = -1;
  for (int i = 0; i < lim3 * lim2 && !exit; i++) {
    int pos = (i / lim3) * (lim3 * lim2) + (fex * lim3) + (i % lim3);
    if (*(x + pos) != 0) {
      num++;
      if (num == n) {
        appo = pos;
        exit = true;
      }
    }
  }
  return *(x + appo);
}