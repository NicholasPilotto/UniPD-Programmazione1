#include <iostream>
using namespace std;

void newriga(bool (*B)[6], bool (*B1)[6], int r);
bool tutta_false(bool (*X)[6], int r);

void leggi(bool (*X)[6]) {
  bool* y = *X;
  for (int i = 0; i < 36; i++) {
    cin >> y[i];
  }
}

void stampa_r(bool (*X)[6], int r) {
  cout << "riga:" << r << '=';

  for (int i = 0; i < 6; i++) {
    cout << X[r][i] << ' ';
  }
  cout << endl;
}

void stampa(bool (*X)[6], int r) {
  for (int i = 0; i < r; i++) {
    stampa_r(X, i);
  }
}

void percorri_cammino(bool (*X)[6], int B2[6], int dim);

int main() {
  int dim;

  bool B[6][6], B1[6][6];
  leggi(B);

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      B1[i][j] = B[i][j];
    }
  }

  int riga;
  int appo = 0;
  for (riga = 1; riga < 6 && !tutta_false(B1, appo); riga++) {
    newriga(B, B1, riga);
    appo++;
  }
  stampa(B1, riga);

  if (tutta_false(B1, riga - 1)) {
    cout << "non c'e' cammino" << endl;
  } else {
    // cout << "c'e' cammmino" << endl;
    //STAMPARE IL CAMMINO PIù A SINISTRA
    cout << "un cammino e':" << endl;
    //riga = grandezza della matrice
    int T[6];

    percorri_cammino(B1, T, riga);

    for (int i = 0; i < 6; i++) {
      cout << "riga " << i << ", colonna " << T[i] << endl;
    }
  }
  return 0;
}

// PRE=(0<=r<=4)&&(le righe r di B e B1 sono definite)
//R=(0<=i<6)&&(tutti gli elementi delle righe della matrice B1 sono stati modificati in base al percorso)
// 1) i = 0 => R
// 2) R&(i < 6) ->
//  - controllo se i = 0 ->
//    - se si allora controllo gli elementi della riga superiore nella posizione i ed i+1
//    - se no, controllo se i = 5 ->
//      - se si, allora controllo gli elementi della riga superiore nella posizione i ed i-1
//      - se no, allora controllo gli elementi della riga superiore nella posizione i ed i-1 ed i+1
// 3) R&(i>=6)&&(tutti gli elementi delle righe della matrice B1 sono stati modificati in base al percorso) => POST
void newriga(bool (*B)[6], bool (*B1)[6], int r) {
  for (int i = 0; i < 6; i++) {
    if (i == 0) {
      if (B1[r][i]) {
        if (!B1[r - 1][i] && !B1[r - 1][i + 1]) {
          B1[r][i] = false;
        }
      }
    } else if (i == 5) {
      if (B1[r][i]) {
        if (!B1[r - 1][i] && !B1[r - 1][i - 1]) {
          B1[r][i] = false;
        }
      }
    } else {
      if (B1[r][i]) {
        if (!B1[r - 1][i] && !B1[r - 1][i + 1] && !B1[r - 1][i - 1]) {
          B1[r][i] = false;
        }
      }
    }
  }
}
// POST=(calcola, nel modo descritto prima, la nuova riga r+1 di B1 usando la riga r+1 di B e la riga r di B1)

bool tutta_false(bool (*X)[6], int r) {
  bool exit = true;
  for (int i = 0; i < 6 && exit; i++) {
    if (X[r][i] == 1) {
      exit = false;
    }
  }
  return exit;
}

// PRE(X è una matrice bool)&&(B2 una array di int di grandezza 6)&&(dim il numero di righe di X)
void percorri_cammino(bool (*X)[6], int B2[6], int dim) {
  bool stop = false;
  // R1=(dim-1>=i>=0)
  // 1.1) i=dim-1 => R1
  // 1.2) R1&&(i>=0) => R1
  // R2=(0<=j<6)&&(!stop)
  // 2.1) (j=0)&&(!stop) => R2
  // 2.2) se il valore nelle coordinate i,j di X è true ->
  //    - se i!=dim-1 ->
  //      -si,  se j==0->
  //        - si, se almeno un elemento della riga sottostante in corrispondeza alla posizione sotto, sotto-destra è true ->
  //          - si, il valore di B2 nella posizione i uguale a j, poi stop = true
  //        - no, se j==5 ->
  //          - si, se almeno un elemento della riga sottostandte in corrispondenza alla posizione sotto, sotto-sinistra ->
  //            - si, il valore di B2 nella posizione i uguale a j, poi stop = true
  //        - no ->
  //          - se se almeno un elemento della riga sottostante in corrispondeza alla posizione sotto, sotto-destra, sotto-sinistra è true ->
  //            - si, il valore di B2 nella posizione i uguale a j, poi stop = true
  //      -no, il valore di B2 nella posizione i uguale a j, poi stop = true
  // 2.3) R2&&(j=6) => POST2
  // 1.3) R&&(i<0) => POST
  for (int i = dim - 1; i >= 0; i--) {
    stop = false;
    for (int j = 0; j < 6 && !stop; j++) {
      if (X[i][j]) {
        if (i != dim - 1) {
          if (j == 0) {
            if (X[i + 1][j] || X[i + 1][j + 1]) {
              B2[i] = j;
              stop = true;
            }
          } else if (j == 5) {
            if (X[i + 1][j] || X[i + 1][j - 1]) {
              B2[i] = j;
              stop = true;
            }
          } else {
            if (X[i + 1][j] || X[i + 1][j + 1] || X[i + 1][j - 1]) {
              B2[i] = j;
              stop = true;
            }
          }
        } else {
          B2[i] = j;
          stop = true;
        }
      }
    }
    // POST2=(è stato rintracciata la colonna più a sinistra della riga i nella quale il percorso continua)
  }
}
// POST=(percorsa tutta X, B2 è stata riempita con le coordinate delle colonne rispettive all'indice di B2, le quali indicano il percorso percorribile più a sinistra)