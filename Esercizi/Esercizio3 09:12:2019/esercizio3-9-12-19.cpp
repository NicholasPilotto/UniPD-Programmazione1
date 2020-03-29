#include <iostream>

using namespace std;

int main() {
  char letter;

  int brackets = 0;

  cout << "Inserisci una sequenza di caratteri, la quale deve terminare con 0: " << endl;

  do {
    cin >> letter;

    if (letter == ')') {
      if (brackets == 0) {
        cout << "\033[1;31mLa sequenza non è bilanciata, ci sono parentesi chiuse senza match \033[0m" << endl;
        return 0;
      }

      brackets--;
    } else if (letter == '(') {
      brackets++;
    }

  } while (letter != '0');

  if (brackets == 0) {
    cout << "\033[1;32mLa sequenza è bilanciata \033[0m" << endl;
  } else if (brackets > 0) {
    cout << "\033[1;31mLa sequenza non è bilanciata, ci sono parentesi aperte senza match \033[0m" << endl;
  }

  return 0;
}