#include <iostream>
using namespace std;

void leggiV(int* X, int n_ele, int lim1, int lim2, int lim3);
void stampaS(int* X, int n_ele, int lim1, int lim2, int lim3, int strato);

int main() {
  int A[400], n_ele, lim1, lim2, lim3, strato;
  cin >> n_ele >> lim1 >> lim2 >> lim3 >> strato;

  leggiV(A, n_ele, lim1, lim2, lim3);

  stampaS(A, n_ele, lim1, lim2, lim3, strato);

  return 0;
}

// PRE=(X contiene almeno n_ele elementi, n_ele, lim1, lim2 e lim3 sono >0, cin contiene n_ele valori)
// R=(0<=i<lim3)
// 1) i = 0 => R
// 2) R&&(i < lim3) ->
//    - inizio ciclo per scorrere gli strati => POST2
//    - inizio ciclio per scorrere le H-fette => POST3
// 3)R&&(i >= lim3) => POST
void leggiV(int* X, int n_ele, int lim1, int lim2, int lim3) {
    for (int i = 0; i < lim3; i++) {
    // PRE=(0<=i<lim3, 0<=j<lim1)
    // R2=(0<=j<lim1)
    // 1) j = 0 => R2
    // 2) R&&(j<lim1)
    //    - inizio ciclo per scorrere le H-fettte => POST3
    // 3) R&&(j>=lim1) => POST2
    for (int j = 0; j < lim1; j++) {
      // PRE=(0<=i<lim3, 0<=j<lim1, 0<=k<lim2)
      // R3=(0<=k<lim2)
      // 1) k = 0 => R3
      // 2) R3&&(k<lim2) -> inserisco in X vista come [lim1][lim2][lim3] il valore letto da cin =>R3
      // 3) R3%%(k>lim2) => POST3
      for (int k = 0; k < lim2; k++) {
        cin >> *(X + (j * lim2 * lim3) + (k * lim3) + i);
      }
      // POST3=(sono stati inseriti tutti i valori letti da cin in X vista come [lim1][lim2][lim3])
    }
    // POST2=(sono stati inseriti i valori in j strati)
  }
}
// POST=(in X vista come int[lim1][lim2][lim3] sono stati letti gli n_ele valori di cin per V-fette)

// PRE=(X contiene almeno n_ele elementi, n_ele, lim1, lim2 e lim3 sono > 0, strato>=0 è lo strato da stampare se contentente valori)
void stampaS(int* X, int n_ele, int lim1, int lim2, int lim3, int strato) {
  bool isFirstValue = true;
  for (int i = 0; i < lim2; i++) {
    isFirstValue = true;
    for (int j = 0; j < lim3; j++) {
      if (*(X + (strato * lim2 * lim3) + (i * lim3) + j) > 0 && *(X + (strato * lim2 * lim3) + (i * lim3) + j) <= n_ele) {
        if (isFirstValue) {
          cout << "r" << i << ":";
          isFirstValue = false;
        }
        cout << *(X + (strato * lim2 * lim3) + (i * lim3) + j) << " ";
      }
    }
    cout << endl;
  }
}
// POST=(sono state stampate tutte le H-fette tutti gli strati con almeno un valore presenti in X vista come [lim1][lim2][lim3])
