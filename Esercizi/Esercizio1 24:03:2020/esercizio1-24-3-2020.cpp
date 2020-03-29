#include<iostream>
using namespace std;

void stampaH(int a[][4][5], int fetta);
void stampaV(int a[][4][5], int fetta);

int main()
{
  int A[3][4][5];
  for(int i=0; i<3; i=i+1) {
    for(int j=0; j<4; j=j+1) {
      for(int k=0; k<5; k=k+1) {
       cin >> A[i][j][k];
      }
    }
  }
  
  char c;
  int f;
  cin >> c >> f;
  cout << "start" << endl;
  if(c == 'H') {
    stampaH(A, f);
  }
  else if (c == 'V') {
    stampaV(A, f);
  } 
  cout << "end" << endl;
  return 0;
}


// PRE=(X contiene strati*4*5 valori e 0<=fetta <4)
/*
  R1=(0=<i<3)&&stampato tutti gli strati di a
  R2=(0=<j<5)&&stampato tutti le righe di a
  1.1) i = 0 => R1
  2.1) j = 0 => R2
  2.2) R2&&(0=<j<5)viene stampato il valore corrispondente alla posizione a[i][fetta][j] e poi j++ => R1
  2.3) R2&&(i >= 5) => POST2
  1.2) stampato tutte le righe del primo strato poi i++ => R1
  1.3) R1&&(i >= 3) => POST1
*/
void stampaH(int a[][4][5], int fetta) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      cout << a[i][fetta][j] << ' ';
    }
    // POST2=(stampa la H-fetta)
    cout << endl;
  }
  // POST1=(stampate tutte le H-fette richieste)
}

// PRE=(X contiene strati*4*5 valori e 0<=fetta<5)
/*
  R1=(0=<i<3)&&stampato tutti gli strati di a
  R2=(0=<j<4)&&stampato tutti le righe di a
  1.1) i = 0 => R1
  2.1) j = 0 => R2
  2.2) R2&&(0=<j<5)viene stampato il valore corrispondente alla posizione a[i][j][fetta] e poi j++ => R1
  2.3) R2&&(i >= 4) => POST2
  1.2) stampato tutte le righe del primo strato poi i++ => R1
  1.3) R1&&(i >= 3) => POST1
*/
void stampaV(int a[][4][5], int fetta) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      cout << a[i][j][fetta] << ' ';
    }
    // POST2=(stampa la V-fetta)
    cout << endl;
  }
  // POST1=(stampate tutte le V-fette richieste)
}
