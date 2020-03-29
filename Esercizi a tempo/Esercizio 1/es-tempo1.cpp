#include<iostream>
using namespace std;

void riempi(int A1[][5], int A2[][5]);
void stampa(int A[][5]);
void cross(int A1[][5], int A2[][5], bool B[][5]);
bool check(int a[5], int b[10]);
void stampa2(bool A[][5]);
void reverseMatrix(int a[5][10], int b[10][5]);

int main()
{
  int A1[10][5];
  int A2[10][5];

  riempi(A1,A2);

  bool B[10][5];

  cross(A1,A2,B);
  cout << endl;
  stampa2(B);
  return 0;
}

void riempi(int A1[][5], int A2[][5]) {
  int counter = 0;
  signed int value;
  int i = 0;
  int j = 0;
  int z = 0;
  int c = 0;
  for (int counter = 0; counter < 50; counter++) {
    cin >> value;
    A1[i][j] = value;
    A2[c][z] = value;

    j++;

    if (j % 5 == 0) {
      i++;
      j = 0;
    }
    c++;
    if(c % 10 == 0) {
      z++;
      c = 0;
    }
}

  stampa(A1);
  cout << endl;
  stampa(A2);
}

void stampa(int A[][5]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}
void stampa2(bool A[][5]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}
//PRE=(A1 è un array multimensiole di [10][5] elementi, A2 A1 è un array multimensiole di [10][5] elementi,
// contentente gli elemnti di A1 disposti in colonne, B è un array bidimensionale di [10][5] elementi bool)
//R1=(0<=i<5)
//R2(0<=j<10)
// 1.1 i = 0 => R1
// 1.2 j = 0 => R2
// 2.2 R&&R2&&(i<5)&&(j<10) -> crichiamo la funzione check passando A1 e c (A2 "girato"), salvando
// il valore restituito in B[j][i] => R
// 3.2 R1&&R2&&(j >= 10) => POST2
// 3.1 R1&&(i >= 5) => POST1

void cross(int A1[][5], int A2[][5], bool B[][5]) {
    int c[5][10];
    reverseMatrix(c, A2);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
        B[j][i] = check(A1[j], c[i]);
    }
    //POST2=(Controllato una riga di A1 con una colonna di A2 e B[j][i] contiene il risultato della verifica)
  }
  //POST1=(B contiene i risultati di tutte le verifiche tra le righe di A1 e le colonne di A2)
}

void reverseMatrix(int a[5][10], int b[10][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      a[i][j] = b[j][i];
    }
  }
}

bool check(int a[5], int b[10]) {
 bool equal = false;



  for (int i = 0; i < 10; i++) {
     for (int j = 0; j < 5; j++) {
       if(a[j] == b[i]) {
         equal = true;
       }
     }
   }

  return equal;
}
