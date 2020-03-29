#include<iostream>
using namespace std;

void stampaH(int X[][4][5], int n_ele, int fetta);
void stampaV(int X[][4][5], int n_ele, int fetta);

int main() {
  cout<<"start"<<endl;
  int A[3][4][5];
  int *p = A[0][0];
  int n_ele;
  cin >> n_ele;
  for(int i = 0; i < n_ele; i = i + 1) {
    cin >> p[i];
  }
  char c;
  int f;
  cin >> c >> f;

  if(c == 'H') {
     stampaH(A, n_ele, f);
  } else {
     stampaV(A, n_ele, f);
  }

  cout << "end" << endl;
  return 0;
}

// PRE=(X contiene strati*4*5 valori e 0<=fetta<5 e 0=<n_ele gli elementi nel vettore)
/*
  R1=(0<=i<3)&&(stampato le H-fette)
  R2=(0<=j<5)

  1) controllo se (fetta * 5) > n_ele
    - è > allora la H-fetta non contiene elementi
    - è < allora la H-fetta contiene elementi
  1.1) i = 0 => R1
  2.1) j = 0 => R2
  2.2) R2&&(j < 5) -> stampo il valore della H-fetta richiesta nella posizione X[i][j] => R2
  2.3) R2&&(j > 5) => POST2
  1.2) stampato l'H-fetta richiesta del primo strato, poi i++ => R1
  1.3) R1&&(i > 3) => POST1
*/

void stampaH(int X[][4][5], int n_ele, int fetta) {
  if((fetta * 5) > n_ele) {
    cout << "fetta richiesta vuota" << endl;
  } else {
   for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      cout << X[i][fetta][j] << ' ';
    }
    // POST2=(stampa la H-fetta)
    cout << endl;
   } 
   // POST1=(stampate tutte le H-fette richieste)
  }
}

void stampaV(int X[][4][5], int n_ele, int fetta) {
  if((fetta * 4) > n_ele) {
    cout << "fetta richiesta vuota" << endl;
  } else {
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 4; j++) {
        if(X[i][j][fetta] != '\0') {
          cout << X[i][j][fetta] << ' ';
        }
      }
      cout << endl;
    } 
  }
}