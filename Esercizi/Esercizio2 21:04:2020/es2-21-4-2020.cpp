#include <iostream>

using namespace std;

struct nodo {
  int info;
  nodo* next;

  nodo(int a = 0, nodo* b = 0) {
    info = a;
    next = b;
  }
};

void stampa(nodo* y) {
  while (y) {
    cout << y->info << ' ';
    y = y->next;
  }

  cout << endl;
}

void match(int* X, int* P, int dimP) {
  for (int i = 0; i < dimP; i++) {
    if (X[i] != P[i]) {
      throw(i);
    }
  }
}

nodo* matchStrato(int* X, int inizio, int lungS, int* P, int dimP) {
  nodo* root = NULL;
  nodo** tail = &root;

  int i = 0;
  while (i < lungS - dimP + 1) {
    try {
      match(X + inizio + i, P, dimP);

      *tail = new nodo(i + inizio);
      tail = &((*tail)->next);

      i += dimP;
    } catch (int index) {
      i++;
    }
  }

  return root;
}

int main() {
  int X[100] = {};
  int lim1, lim2, lim3;
  int nele;
  cin >> lim1 >> lim2 >> lim3 >> nele;

  for (int i = 0; i < nele; i++) {
    cin >> X[i];
  }

  int P[20];
  int dimP;
  cin >> dimP;

  for (int i = 0; i < dimP; i++) {
    cin >> P[i];
  }

  nodo* Y = NULL;
  nodo** tail = &Y;

  int full = nele / (lim2 * lim3);
  int rest = nele % (lim2 * lim3);

  for (int i = 0; i < full; i++) {
    *tail = matchStrato(X, i * lim2 * lim3, lim2 * lim3, P, dimP);

    while (*tail) {
      tail = &((*tail)->next);
    }
  }

  if (rest != 0) {
    *tail = matchStrato(X, full * lim2 * lim3, rest, P, dimP);
  }

  stampa(Y);

  return 0;
}