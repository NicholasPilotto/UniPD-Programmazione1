#include "BST.h"

#include <iostream>

using namespace std;
using namespace BST;

// PRE=(ALbero(a) ben formato)
void BST::stampa_l(nodo* r) {
  if (r) {
    cout << r->info << '(';
    stampa_l(r->left);
    cout << ',';
    stampa_l(r->right);
    cout << ')';
  } else {
    cout << '_';
  }
}
// POST=(stampa Albero(a) in modo lineare)

// PRE=(ALbero(a) ben formato, y numero natuale)
nodo* BST::insert(nodo* r, int y) {
  if (!r) {
    return new nodo(y);
  }

  if (r->info >= y) {
    r->left = insert(r->left, y);
  } else {
    r->right = insert(r->right, y);
  }
  return r;
}
//POST=(inserisce y in albero(a), in modo tale che albero(a) sia ancora BST)
/*
  CASO BASE1: albero vuoto (riga 24):
    - se ci troviamo in questo caso significa che l'albero è vuoto, quindi il nodo
      padre era una foglia e quindi si deve aggiungere un nuovo nodo, con campo info = y e lo si
      ritorna attraverso il return

  CASO RICORSIVO: campo info >= y (riga 28):
    - se campo info del nodo corrente >= y, per proprietà degli alberi BST, il nodo con campo info
      uguale a y si dovrà inseririe nel sottoalbero sinistro. Per fare ciò si richiama ricorsivamente
      la funzione passando per valore il nodo sinistro al corrente e il valore y.
      se campo info del nodo corrente < y, per proprietà degli alberi BST, il nodo con campo info
      uguale a y si dovrà inseririe nel sottoalbero destro. Per fare ciò si richiama ricorsivamente
      la funzione passando per valore il nodo destro al corrente e il valore y.

      La chiamata ad ogni funzione ricorsiva rispetta la PRE, in quanto, da CASO BASE1, abbiamo la certezza
      che l'albero esista e sia ben formato
      La chiamata ad ogni funzione ricorsiva rispetta la POST, in quanto, da CASO BASE1 + CASO RICORSIVO,
      viene inserito il nodo nella posizione corretta dell'albero, in modo tale da rispettare le proprietà
      degli alberi BST
*/

// PRE=(albero(a) ben formato, x numero naturale)
bool BST::search(nodo* r, int x) {
  bool a = false;
  if (!r) {
    return false;
  }

  if (r->info == x) {
    return true;
  }

  if (r->info >= x) {
    return search(r->left, x);
  } else {
    return search(r->right, x);
  }
  return false;
}
// POST=(ritorna TRUE sse x è presente in albero(a))

// PRE=(albero(a) ben formato e non vuoto)
nodo* BST::max(nodo* r) {
  if (!r->right) {
    return r;
  }

  return max(r->right);
}
// POST=(ritorna il nodo con campo info maggiore di tutti gli altri nodi)

// PRE=(albero(a) ben formato e non vuoto)
nodo* BST::min(nodo* r) {
  if (!r->left) {
    return r;
  }

  return min(r->left);
}
// POST=(ritorna il nodo con campo info minore di tutti gli altri nodi)

// PRE=(albero(a) ben formato)
int BST::altezza(nodo* r) {
  if (!r) {
    return -1;
  }

  int a = altezza(r->left);
  int b = altezza(r->right);

  if (a > b) {
    return 1 + a;
  } else {
    return 1 + b;
  }
}
// POST=(ritorna l'altezza di albero(a))

// PRE=(albero(a) ben formato)
int BST::altMin(nodo* r) {
  if (!r) {
    return 0;
  }

  int a = altezza(r->left);
  int b = altezza(r->right);

  if (a < b) {
    return a;
  } else {
    return b;
  }
}
// POST=(ritorna il numero di nodi che compongono il cammino più breve tra
// la radice e una foglia)