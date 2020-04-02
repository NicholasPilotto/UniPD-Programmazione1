#include <iostream>

#define size 10

using namespace std;

void leggi(int X[],int m);
int trovaporz(int Y[], int q);

int main() {
    int array[size];

    int g = 0;

    cout << "Quanto deve essere grande l'array?: ";
    cin >> g;

    cout << "Inserisci i valori nell'array:" << endl;
    leggi(array, g);

    int result = trovaporz(array, g);

    cout << "k=" << result << endl;


    
    return 0;
}

/*
  * X e' un array ti tipo intero con grandezza <= 100
  * 0 < m <= 100
*/
void leggi(int X[],int m) {
    
    for (int i = 0; i < m; i++) {
        cin >> X[i];
    }
    
}
/*
  * POST
  * legge 0 <= n < 100 e li scrive nell'array
*/

/*
  * PRE: 
  * Y e' un array ti tipo intero con grandezza <= 100
  * 0 < q <= 100
 */
int trovaporz(int Y[], int q) {
    int porz = 1;

    /* 
    * R = (0 <= i < q - 1) && la porzione e' compresa tra Y[0..q-1]
    * 1) la condizione e' vera nel primo ciclo
    * 2) la condizione e' vera ogni volta che il ciclo arriva nel punto R
    * 3) R && (i > q - 1) => POST
    */

    for /*R*/ (int i = 0; i < q - 1; i++) {
        if (Y[i] < Y[i + 1]) {
            porz++;
        } else {
            return porz;
        }
    }


    
    
    return porz;
}

/*
  * POST
  * ritorna un valore intero rappresentate la lunghezza della porzione piu' grande e crescente dell'array partendo da 0
*/
