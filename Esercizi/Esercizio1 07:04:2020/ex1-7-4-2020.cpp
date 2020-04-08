#include <iostream>
using namespace std;

#define KM 21.975f

struct orario {
  int ore, minuti, secondi;
  orario(int a = 0, int b = 0, int c = 0) {
    ore = a;
    minuti = b;
    secondi = c;
  }

  orario& operator=(orario x) {
    ore = x.ore;
    minuti = x.minuti;
    secondi = x.secondi;
    return *this;
  }
};

struct rileva {
  int ril;
  int corr;
  orario time;

  rileva(int a = 0, int b = 0, orario c = orario()) {
    ril = a;
    corr = b;
    time = c;
  }
};

struct corsa {
  rileva rilevazioni[3];
  int rilevazione;

  corsa(int b = 0) {
    rilevazione = b;
  }
};

istream& operator>>(istream& s, orario& x);
istream& operator>>(istream& s, rileva& x);
int hour_to_second(orario time);

orario operator-(orario a, orario b);

int main() {
  int ncorr;
  cin >> ncorr;
  orario z;
  cin >> z;  //presuppone che abbiate definito operator>> per orario, z non serve nel resto del programma

  corsa gara[ncorr];

  rileva r;

  cin >> r;
  while (r.ril != -1) {
    gara[r.corr].rilevazioni[r.ril] = r;
    gara[r.corr].rilevazione++;
    cin >> r;
  }

  // PRE=(regular è una variabile bool inizialmente false)&&(ncorr variabile int>=0)&&(gara variabile struttura corsa)&&(KM kilometri totali della gara)
  // R=(0<=i<ncorr)
  // 1) i = 0 => R
  // 2) R&&(i<ncorr) ->
  //  - controllo il numero di rilevazioni del corridore di indice i ->
  //    - se le rilevazioni del corridore indice i < 3
  //      - il corridore ha usato una scorciatoia, stampo "i ': salto sensore'" e poi regular diventa false
  //      - altrimenti ->
  //        - o1 variabile orario contentente la differenza dei tempi rilevati nel primo tratto, o2 variabile orario contentente la differenza dei tempi rilevati nel secondo tratto,
  //          calcolo il numero di secondi totali di o1 e lo salvo in seconds1, calcolo il numero di secondi totali di o2 e lo salvo in seconds2 ->
  //            - se seconds1 / KM < 100 oppure seconds2 / KM < 100 ->
  //              - il corridore ha usato un veicolo, stampo "i ': tempo sospetto'" e poi regular diventa false
  //  3) i>= ncorr => POST
  bool regular = true;
  for (int i = 0; i < ncorr; i++) {
    if (gara[i].rilevazione < 3) {
      regular = false;
      cout << i << ": salto sensore" << endl;
    } else {
      orario o1 = gara[i].rilevazioni[1].time - gara[i].rilevazioni[0].time;
      orario o2 = gara[i].rilevazioni[2].time - gara[i].rilevazioni[1].time;
      int seconds1 = hour_to_second(o1);
      int seconds2 = hour_to_second(o2);

      if (seconds1 / KM < 100.0 || seconds2 / KM < 100) {
        regular = false;
        cout << i << ": tempo sospetto" << endl;
      }
    }
  }

  if (regular) {
    cout << "gara regolare" << endl;
  }
  // POST=(sono stati controllati tutti i corridori, se nessuno ha commesso infrazioni è stato stampato "gara regolare", altrimenti sono stati segnalati i corridori e la loro infrazione)
  //controllo dei problemi e stampa in ordine
  return 0;
}

// PRE=(s è la finestra di lettura dei dati, x è una variabile orario dove verranno salvati i dati ricevuti in lettura da s)
istream& operator>>(istream& s, orario& x) {
  int h;
  int mim;
  int sec;
  cin >> h >> mim >> sec;
  x.ore = h;
  x.minuti = mim;
  x.secondi = sec;
  return s;
}
// POST=(sono stati letti i dati da s e salvati nella struttira orario x)

// PRE=(s è la finestra di lettura dei dati, x è una variabile orario dove verranno salvati i dati ricevuti in lettura da s)
istream& operator>>(istream& s, rileva& x) {
  int idSens;
  int idPar;
  orario orario;

  cin >> idSens;
  cin >> idPar;
  cin >> orario;

  x.ril = idSens;
  x.corr = idPar;
  x.time = orario;

  return s;
}
// POST=(sono stati letti i dati da s e salvati nella struttira rileva x)

// PRE=(a, b sono due variabili struttura orario, non vuote)
orario operator-(orario a, orario b) {
  orario o;
  o.ore = a.ore - b.ore;
  o.minuti = a.minuti - b.minuti;
  o.secondi = a.secondi - b.secondi;
  return o;
}
// POST=(è stata effettuata la sottrazione di tutti i campi delle struttute e salvati i risultati in una struttuta orario o)

// PRE=(time è una variabile struttura orario non nulla)
int hour_to_second(orario time) {
  return (time.ore * 60 * 60) + (time.minuti * 60) + time.secondi;
}
// POST=(calcolata la variabile struttura time in secondi)