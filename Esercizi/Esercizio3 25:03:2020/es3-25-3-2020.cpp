#include<iostream>
using namespace std;

void cake(int *A, int ns, int nr, int nc, int dim);

int main() {
  int n_ele;
  int lim1;
  int lim2;
  int lim3;
  int X[400];
  cin >> n_ele;
  for(int i = 0; i < n_ele; i++){
   cin >> X[i];
  }
  cin >> lim1 >> lim2 >> lim3;
  cout<<"start" << endl;
  cake(X, lim1, lim2, lim3, n_ele);
  cout<<"end"<<endl;
}


void cake(int *A, int ns, int nr, int nc, int dim) {
  for (int i = 0; i < ns; i++) {
    if(((i * nr * nc) < dim) {
      cout << "strato" << i << endl;
      for (int j = 0; j < nr; j++) {
        if((i * nr * nc) + (j * nc)) <= dim) {
          cout << "r" << j << ":";
          for (int k = 0; k < nc; k++) {
            if(((i * nr * nc) + (j * nc) + k) <= dim) {
              cout << *(A + (i * nr * nc) + (j * nc) + k) << ' ';
            }
          }
        }
        cout << endl;
      }
    }
  }
}

// void cake(int *A, int ns, int nr, int nc) {
//   for (int i = 0; i < ns; i++) {
//     cout << endl;
//     if(*(A + (i * nr * nc)) != '\0') {
//     cout << "strato" << i << endl;
//     for (int j = 0; j < nr; j++) {
//       if(*(A + (i * nr * nc) + (j * nc) + 0) != '\0') {
//         cout << "r" << j << ":";
//         for (int k = 0; k < nc; k++) {
//           int value = *(A + (i * nr * nc) + (j * nc) + k);
//           if(value != '\0') {
//             cout << value << ' ';
//           }
//         }
//       cout << endl;
//       }
//     }
//     }
//   }
// }