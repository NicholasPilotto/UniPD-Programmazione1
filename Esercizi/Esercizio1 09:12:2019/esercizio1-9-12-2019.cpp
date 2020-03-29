#include <iostream>
#include <math.h>

using namespace std;

bool controllaChar(char c);

int main() {
  char p1;
  char p2;

  char w;

  cout << "\nInserisci la mossa del primo giocatore: ";
  cin >> p1;
  cout << "Inserisci la mossa del secondo giocatore: ";
  cin >> p2;

  if (controllaChar(p1) && controllaChar(p2)) {
    if (p1 != p2) {
      if ((p1 == 'f' && p2 == 'c') || (p1 == 'c' && p2 == 's') ||
          (p1 == 's' && p2 == 'f')) {
        w = p1;
      } else {
        w = p2;
      }

      cout << "Il vincitore è " << w << endl << endl;
    } else {
      cout << "Le mosse sono uguali" << endl << endl;
    }
  } else {
    cout << "Mosse non valide" << endl << endl;
  }

  return 0;
}

bool controllaChar(char c) {
  switch (c) {
  case 'f':
    return true;
    break;
  case 's':
    return true;
    break;
  case 'c':
    return true;
    break;

  default:
    return false;
    break;
  }
}