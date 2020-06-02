#include <iostream>

#include "BST.h"

using namespace std;
using namespace BST;

int main() {
  //prepara un albero iniziale non triviale
  nodo* r = new nodo(15, new nodo(7), new nodo(19));
  r->left->right = new nodo(9, new nodo(8));
  r->right->right = new nodo(25, new nodo(22));

  bool stop = false;
  int func = 0;
  nodo* c = NULL;
  while (!stop) {
    cin >> func;

    if (func == 0) {
      stop = true;
    } else if (func == 1) {
      BST::stampa_l(r);
      cout << endl;
    } else if (func == 2) {
      int a = 0;
      cin >> a;
      r = BST::insert(r, a);
      BST::stampa_l(r);
      cout << endl;
    } else if (func == 3) {
      int a = 0;
      cin >> a;
      bool b = BST::search(r, a);
      if (b) {
        cout << "valore " << a << " presente" << endl;
      } else {
        cout << "valore " << a << " non presente" << endl;
      }
    } else if (func == 4) {
      int b = 0;
      cin >> b;
      if (r) {
        c = b == 1 ? BST::max(r) : BST::min(r);
        cout << c->info << endl;
      }
    } else if (func == 5) {
      cout << BST::altezza(r) << endl;
    } else if (func == 6) {
      cout << BST::altMin(r) << endl;
    }
  }

  return 0;
}