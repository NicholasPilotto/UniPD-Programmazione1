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

  //controllo dei problemi e stampa in ordine
  return 0;
}

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

orario operator-(orario a, orario b) {
  orario o;
  o.ore = a.ore - b.ore;
  o.minuti = a.minuti - b.minuti;
  o.secondi = a.secondi - b.secondi;
  return o;
}

int hour_to_second(orario time) {
  return (time.ore * 60 * 60) + (time.minuti * 60) + time.secondi;
}