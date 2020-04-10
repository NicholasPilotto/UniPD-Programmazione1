#include <iostream>
using namespace std;

//qualche funzione ausiliaria
void stampa_fetta(int X[], int lung, int lim2, int lim3);
int h_length(int hf, int n_ele, int lim2, int lim3);
int next_index(int index, int lim2, int lim3);

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
  cin >> hf;  // fetta da trattare

  int lung = h_length(hf, n_ele, lim2, lim3);

  int hFetta[lung];

  int* h_fetta = (X + (hf * lim3));  //puntatore al primo elemento dell'h fetta
  int matches = 0;

  // PRE=(hf>=0 HFetta da controllare)&&(matches>=0 numero di valori corrispondendi)&&(h_fetta puntatore al primo elemento della fetta)&&(P array di valori da cercare ed evetualmente eliminare nella H Fetta)
  // &&(lung>=0 lunghezza della H Fetta)
  // R=(0<=i<lung)
  // 1) i=0 => R
  // 2) i<lung => R
  //  - se il valore della H Fetta = al valore in posizione matches di P
  //    - si, incremento matches
  //    - no, mi calcono l'indice del valore i-matches per scambiarli nella H Fetta, poi li scambio
  // 3) i>=lung => POST
  for (int i = 0; i < lung; i++) {
    int index = next_index(i, lim2, lim3);
    if (*(h_fetta + index) == P[matches]) {
      matches++;
    } else {
      int a = next_index(i - matches, lim2, lim3);
      *(h_fetta + a) = *(h_fetta + index);
    }
  }
  // POST=(tutta la H Fetta è stata controllata, eliminati gli eventuali valori che corrispondevano ai valori in P)
  if (matches == nP) {
    cout << "pattern consumato tutto" << endl;
  } else {
    cout << "pattern rimasto ";
    for (int i = matches; i < nP; i++) {
      cout << P[i] << ' ';
    }
    cout << endl;
  }
  cout << "la H-fetta " << hf << " e' diventata:" << endl;
  stampa_fetta(h_fetta, lung - matches, lim2, lim3);
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