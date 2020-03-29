#include <iostream>
#include <list>
#include <map>

using namespace std;

int main() {
  list<char> lista;
  map<int, char> brackets;

  char array[20];

  brackets[41] = '(';
  brackets[93] = '[';
  brackets[125] = '{';

  char c;
  cout << "Inserisci una sequenza di caratteri: ";
  cin >> c;

  int i = 0;

  while (c != '0') {
    if ((c == '{') || (c == '[') || (c == '(')) {
      array[i] = c;
      i++;
    } else {
      if (array[0] != '\0') {
        if (array[i - 1] == brackets[(int)c]) {
          array[i - 1] = '\0';
          i--;
        } else {
          cout << "Parentesi accavallate" << endl;
          return 0;
        }
      } else {
        cout << "Troppe parentesi chiuse" << endl;
        return 0;
      }
    }
    cin >> c;
  }

  if (array[0] != '\0') {
    cout << "Troppe parentesi aperte" << endl;
  } else {
    cout << "Sequenza bilanciata" << endl;
  }

  return 0;
}