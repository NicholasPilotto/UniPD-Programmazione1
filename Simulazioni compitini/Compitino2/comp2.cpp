#include <iostream>

using namespace std;

int h_length(int hf, int n_ele, int lim2, int lim3);
int next_index(int index, int lim2, int lim3);
void stampa_fetta(int* X, int lung, int lim2, int lim3);

int main() {
  int X[400];
  int P[20];
  int n_ele;
  int nP;
  int lim1, lim2, lim3;
  cin >> n_ele;
  for (int i = 0; i < n_ele; i++) {
    cin >> X[i];
  }
  cin >> lim1 >> lim2 >> lim3;
  if (lim1 * lim2 * lim3 < n_ele) {
    n_ele = lim1 * lim2 * lim3;
  }
  cin >> nP;
  for (int i = 0; i < nP; i++) {
    cin >> P[i];
  }

  cout << "start" << endl;
  int hf;
  cin >> hf;

  int matches = 0;
  int* start = (X + (hf * lim3));
  int lung = h_length(hf, n_ele, lim2, lim3);

  //  R=(0<=i<lung)
  //  1) i==0 => R
  //  2) i<lung => R
  //  - calcolo l'indice dell'elemento da controllare della H Fetta
  //  - se l'elemento in posizione i della H Fetta è uguale al valore in corrispondeza di matches in P ->
  //    - si, incremento metches
  //  3) i>=lung => esco dal ciclo
  for (int i = 0; i < lung; i++) {
    int index = next_index(i, lim2, lim3);

    if (*(start + index) == P[matches]) {
      matches++;
    }
  }

  int appo = 0;
  if (matches == nP) {
    for (int i = 0; i < lung; i++) {
      int index = next_index(i, lim2, lim3);
      if (*(start + index) != P[appo]) {
        int a = next_index(i - appo, lim2, lim3);
        *(start + a) = *(start + index);
      } else {
        appo++;
      }
    }
    cout << "H-fetta " << hf << " rimasti i seguenti " << lung - nP << " valori:" << endl;
    stampa_fetta(start, lung - nP, lim2, lim3);
  } else {
    cout << "H-fetta 2 non è cambiata, i suoi 6 valori seguono:" << endl;
    stampa_fetta(start, lung, lim2, lim3);
  }

  // ciclo di esame dell’H-fetta hf da fare

  cout << "end" << endl;
  return 0;
}

void stampa_fetta(int* X, int lung, int lim2, int lim3) {
  for (int i = 0; i < lung; i++) {
    int index = next_index(i, lim2, lim3);
    cout << *(X + index) << ' ';
  }
  cout << endl;
}

int h_length(int hf, int n_ele, int lim2, int lim3) {
  int nsp = n_ele / (lim2 * lim3);  //numero strati pieni
  int eus = n_ele % (lim2 * lim3);  //elementi dell'ultimo strato
  int rpus = eus / lim3;            //(numero) righe piene ultimo strato
  int ur = eus % lim3;              //(numero di elementi nell') ultima riga

  int dimH = lim3 * nsp;  //lunghezza minima di una H-fetta (se hf > rpus)
  if (hf < rpus) {
    dimH += lim3;
  } else if (hf == rpus) {
    dimH += ur;
  }

  return dimH;
}

int next_index(int index, int lim2, int lim3) {
  return (index / lim3) * lim2 * lim3 + (index % lim3);
}