#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 0
bool palindroma(char *S, int n);
// POST = ritorna true se e solo se S e' palindroma

int main() {
  int lung;
  char S[100];
  cin.getline(S, 100);      // legge una riga di caratteri da cin
  lung = cin.gcount() - 1;  // gcount ritorna il numero di caratteri letti(compreso il terminatore '\n')

  // scrivere la vostra implementazione qui
  bool pal = palindroma(S, lung);

  if (pal) {
    cout << "la stringa e' palindroma" << endl;
  } else {
    cout << "la stringa non e' palindroma" << endl;
  }
  return 0;
}

// PRE=(S è una stringa di lunghezza n >= 0)
// (1) CASO BASE 1:
// - n == 1
// -- questo è il caso base che si viene a verificare quando si ha una stringa di lunghezza dispari, infatti,
//    eliminando ricorsivamente i caratteri agli estremi, rimmarrà un solo carattere, quello nel mezzo.
//    Viene ritornato true, in quanto un carattere è uguale a se stesso, quindi palindromo
//
// (2) CASO BASE 2:
// - n == 0
// -- questo è il caso base che si viene a verificare quando si ha una stringa di lunghezza pari, infatti,
//    eliminando ricorsivamente i caratteri agli estremi, non rimmarrà nessun carattere.
//    Viene ritornato true, in quanto un carattere nullo è uguale a se stesso, quindi palindromo
//
// (3) CASO BASE 3:
// - return false
// -- questo è il caso base che si verifica quando non c'è un match tra i due caratteri agli estremi della stringa.
//    Ritorna false, in quanto non si è verificato un match, la stringa non può essere palindroma
//
// CASO RICORSIVO:
// PRE_RIC: n >= 0
// dimostro che n - 2 >= 0:
// n - 2 > 0 in quanto da (1) e (2) abbiamo n != 1 e n != 0, quindi
//    (n - 2) > (1)
//    [(n > 1) - 2] >= 0
//    n > -1 -> n >= 0
//
// S stringa con length(S) == n
// dimostro che S ha almeno n caratteri:
//    length(S + 1) >= n in quanto per PRE abbiamo length(S) == n, n_ric = n - 2, quindi
//    facendo avanzare S di 1, e togliendo 2 alla capacità massima, stiamo avanzando di un carattere
//    e togliendone due alla dimensione totale
//
// CASO INDUTTIVO:
// return palindroma(S + 1, n - 2):
//   Avendo dimostrato di aver rispettato PRE_RIC, possiamo assumere per corretta la POST_RIC, e quindi
//   palindroma(S + 1, n - 2) ritorna true sse [S ... S+n] è palindroma, e per (3) se una coppia di caratteri
//   agli estremi fosse stata diversa, la funzione avrebbe terminato ritornando false e quindi ritorniamo true
//   sse i caratteri correnti (primo e ultimo) sono uguali && la sottostringa [S+1 ... S+(n-2)] è palindroma

bool palindroma(char *S, int n) {
  // CASO BASE 1
  // PRE=(n numero intero)
  if (n == 1) {
    return true;
  }
  // POST=(ritorna true sse n == 1)

  // CASO BASE 2
  // PRE=(n numero intero)
  if (n == 0) {
    return true;
  }
  // POST=(ritorna true sse n ==0)

  // CASO RICORSIVO
  // PRE=(n >= 0)
  if (S[0] == S[n - 1]) {
    // CASO INDUTTIVO
    return palindroma(S + 1, n - 2);
  }

  // CASO BASE 3
  return false;
}
// POST=(la funzione ritorna true se e solo se S è palindroma)