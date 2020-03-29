#include <math.h>
#include <iostream>

using namespace std;

bool controllaChar(char c);

int main() {
  char p1;
  char p2;

  char w;

  int v_p1 = 0;
  int v_p2 = 0;

  char gioca;

  int giocate_totali_valide = 0;
  int giocate_errate = 0;
  int giocate_totali = 0;

  cout << "Per giocare premere g, per smettere premere n" << endl;

  do {
    cout << "\nInserisci la mossa del primo giocatore: ";
    cin >> p1;
    cout << "Inserisci la mossa del secondo giocatore: ";
    cin >> p2;

    if (controllaChar(p1) && controllaChar(p2)) {
      if (p1 != p2) {
        if ((p1 == 'f' && p2 == 'c') || (p1 == 'c' && p2 == 's') ||
            (p1 == 's' && p2 == 'f')) {
          v_p1++;
        } else {
          v_p2++;
        }

        giocate_totali_valide++;
      } else {
        cout << "Le mosse sono uguali" << endl << endl;

        giocate_errate++;
      }
    } else {
      giocate_errate++;
      cout << "Mosse non valide" << endl << endl;
    }

    giocate_totali++;

    cout << "Vuoi giocare ancora?: ";
    cin >> gioca;
  } while (gioca == 'g');

  cout << "-----------------" << endl;
  cout << "Le giocate totali sono state: " << giocate_totali << endl;
  cout << "Le giocate errate totali sono state: " << giocate_errate << endl;
  cout << "Le giocate totali valide sono state: " << giocate_totali_valide
       << endl;

  cout << "\nIl giocatore 1 ha vinto: " << v_p1 << " volte" << endl;
  cout << "Il giocatore 2 ha vinto: " << v_p2 << " volte" << endl << endl;

  if (v_p1 > v_p2) {
    cout << "Il vincitore è il giocatore 1!" << endl;
  } else {
    cout << "Il vincitore è il giocatore 2!" << endl;
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