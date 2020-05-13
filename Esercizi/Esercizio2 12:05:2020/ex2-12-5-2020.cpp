// // #include "Algocrypt.h"

// #include <ctype.h>
// #include <math.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// #define LENGTH 32

// // #define DEBUG

// //* methods
// //? ----
// // transform int to HEX and retruned as a string
// char *DECIMAL_HEX(int);
// // transform HES, passed as a string, and returned as int
// int HEX_DECIMAL(char *);
// //? ----
// // find element in an array, if there is it, return the position
// int FIND_IN_ARRAY(char *, char);
// //? ----
// // is set something?
// bool IS_SET(char *);
// //? ----
// // crypt method
// char *CRYPT(char *word);
// // decrypt method
// char *DECRYPT(char *word);

// int main(int argc, char *argv[]) {
// #ifndef DEBUG
//   char word[strlen(argv[2])];
//   // creating an array with argv size

//   char c[] = "-c";
//   char d[] = "-d";

//   /*
//     -c defines that the algorithm have to crypt the string
//     -d defines that the algorithm have to decrypt the string
//   */

//   if (strcmp(argv[1], c) == 0) {
//     // assing the argv value to the array
//     strcpy(word, argv[2]);
//     // creating the array that will contain the crypted word, the size of the
//     // array is LENGTH + 1 becuase C insert a finel character for the ending of
//     // the string
//     char crypted[LENGTH + 1] = {};
//     // char *crypted = malloc(sizeof(int) * (LENGTH + 1));
//     strcpy(crypted, CRYPT(word));

//     if (IS_SET(crypted)) {
//       printf("%s\n", crypted);
//     } else {
//       printf("String is incorrect\n");
//     }
//   } else if (strcmp(argv[1], d) == 0) {
//     // decrypt
//     char decrypted[100] = {};
//     strcpy(word, argv[2]);
//     strcpy(decrypted, DECRYPT(word));
//     printf("%s\n", decrypted);
//   } else {
//     //error
//   }
// #endif
// #ifdef DEBUG
//   char word[5] = {'c', 'i', 'a', 'o'};
// #endif

//   return 0;
// }

// char *DECIMAL_HEX(int number) {
//   char hexaDeciNum[3];

//   static char changed[3];

//   // counter for hexadecimal number array
//   int i = 0;
//   if (number == 0) {
//     hexaDeciNum[i] = number;
//     i++;
//   } else {
//     while (number != 0) {
//       // temporary variable to store remainder
//       int temp = number % 16;

//       // check if temp < 10
//       if (temp < 10) {
//         hexaDeciNum[i] = temp + 48;
//         i++;
//       } else {
//         hexaDeciNum[i] = temp + 55;
//         i++;
//       }

//       number = number / 16;
//     }
//   }

//   // printing hexadecimal number array in reverse order
//   int a = 0;
//   for (int j = i - 1; j >= 0; j--) {
//     changed[a] = hexaDeciNum[j];
//     a++;
//   }

//   return changed;
// }
// //? CRYPT
// char *CRYPT(char *word) {
//   static char crypted[LENGTH];

//   // set time to NULL
//   srand(time(NULL));
//   // creating the seed for the crypting process
//   int seed = (rand() % 20) + 15;
//   // creating the key variable
//   char key[5];
//   // setting the key variable with the HEX seed
//   strcpy(key, DECIMAL_HEX(seed));

//   // allows character array
//   static char symbol_array[65] = {
//       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
//       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
//       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
//       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//       '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '/', '@', '_'};

//   // the length of word
//   int word_length = (int)strlen(word);

//   // the length of symbol_array
//   int array_length = strlen(symbol_array);

//   // looping through the word
//   for (int i = 0; i < LENGTH - 4; i++) {
//     // checking if the index is lower than word_length
//     if (i < word_length) {
//       // the position of the character in symbol_array
//       int position = FIND_IN_ARRAY(symbol_array, word[i]);

//       // TODO: errors handling

//       if (position != -1) {
//         if ((i % 2) == 0) {
//           // checking if the position + seed is greater than
//           if ((position + seed) >= array_length) {
//             // no oversize the array
//             crypted[i] = symbol_array[seed - (strlen(symbol_array) - position)];
//           } else {
//             crypted[i] = symbol_array[position + seed];
//           }
//         } else if ((i % 2) != 0) {
//           // checking if the position + seed is greater than
//           if ((position - seed) < 0) {
//             // no oversize the array
//             crypted[i] = symbol_array[strlen(symbol_array) - (seed - position)];
//           } else {
//             crypted[i] = symbol_array[position - seed];
//           }
//         }
//       } else if (position == -1) {
//         crypted[0] = '\0';
//         return crypted;
//       }
//     } else if (i >= word_length) {
//       // checking if the index is greateter than word's length
//       // random between 0 to 64
//       int random = (rand() % 65);
//       crypted[i] = symbol_array[random];
//     }
//   }

//   // adding 228 to the word length to have alphanumerical hex and for a better
//   // crypt of the number
//   int length_to_crypt = word_length - 1 + 228;

//   // creating the array for the hex value
//   char hex_length[3];

//   // inserting the value into the array
//   strcpy(hex_length, DECIMAL_HEX(length_to_crypt));

//   // setting hex_value into crypted
//   crypted[28] = hex_length[0];
//   crypted[29] = hex_length[1];

//   // setting key value into crypted
//   crypted[30] = key[0];
//   crypted[31] = key[1];

//   // returning crypted
//   return crypted;
// }

// //? DECRYPT
// char *DECRYPT(char *word) {
//   // allows character array
//   static char symbol_array[65] = {
//       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
//       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
//       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
//       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//       '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '/', '@', '_'};

//   // the length of word
//   int word_length = (int)strlen(word);

//   char hex[3] = {word[28], word[29]};
//   int length = 0;
//   length = HEX_DECIMAL(hex) - 227;

//   char key[3] = {word[30], word[31]};
//   int seed = HEX_DECIMAL(key);

//   static char *decrypted = new char[length + 1];

//   for (int i = 0; i < length; i++) {
//     int pos = FIND_IN_ARRAY(symbol_array, *(word + i));

//     if (pos != -1) {
//       if ((i % 2) == 0) {
//         decrypted[i] = symbol_array[pos - seed];
//       } else {
//         decrypted[i] = symbol_array[pos + seed];
//       }
//     } else {
//       decrypted[0] = '\0';
//       return decrypted;
//     }
//   }

//   return decrypted;
// }

// //? OTHER USEFULL METHODS
// signed int FIND_IN_ARRAY(char *array, char character) {
//   for (int i = 0; i < (int)strlen(array); i++) {
//     if (array[i] == character) {
//       return i;
//     }
//   }

//   return -1;
// }

// bool IS_SET(char *word) {
//   return (word[0] != '\0');
// }

// int HEX_DECIMAL(char *word) {
//   return (int)strtol(word, NULL, 16);
// }

#include <iostream>
using namespace std;

struct nodo {
  int info;
  nodo* next;
  nodo(int a = 0, nodo* b = 0) {
    info = a;
    next = b;
  }
};
nodo* elimOne(nodo* L, int x);
void elimOne2(nodo* L, int x);
void elimOne3(nodo*& L, int x);

nodo* faiL(int n) {
  if (n) {
    int x;
    cin >> x;
    return new nodo(x, faiL(n - 1));
  }
  return 0;
}

void stampa(nodo* L) {
  if (L) {
    cout << L->info << ' ';
    stampa(L->next);
  } else {
    cout << endl;
  }
}

nodo* clone(nodo* L) {
  if (L) {
    return new nodo(L->info, clone(L->next));
  }
  return 0;
}

int main() {
  int m, x;
  cin >> m >> x;
  nodo* L = faiL(m);
  //stampa(L);

  nodo *L2, *L3;
  L2 = clone(L);
  if (L2->info == x) {
    L2 = new nodo(x + 1, L2);
  }
  L3 = clone(L);

  L = elimOne(L, x);

  if (L2) {
    elimOne2(L2, x);
  }

  if (L3) {
    elimOne3(L3, x);
  }

  stampa(L);
  stampa(L2);
  stampa(L3);

  return 0;
}

// PRE=(Lista(L) ben formata, vL(n) = L(n))
nodo* elimOne(nodo* L, int x) {
  if (!L) {
    return NULL;
  }
  if (L->info == x) {
    return elimOne(L->next, x);
    delete L;
  }

  L->next = elimOne(L->next, x);
  return L;
}
// POST=(restituisce una lista vL(L)@L(L) a parte i nodi con campo info = x, che, se esistono, vanno deallocati)

// PRE=(Lista(L) ben formata e non vuota e col primo nodo tale che il suo campo info non sia x, vLista(L)=Lista(L))
void elimOne2(nodo* L, int x) {
  if (L->next) {
    elimOne2(L->next, x);
    if (L->next->info == x) {
      nodo* appo = L->next->next;
      delete L->next;
      L->next = appo;
    }
  }
}
// POST=(Lista(L) contiene tutti i nodi di vLista(L)@Lista(L) a parte i nodi con campo info = x, che, se esistono, vanno deallocati)

// PRE=(Lista(L) ben formata e VLista(L)=Lista(L))
void elimOne3(nodo*& L, int x) {
  if (L) {
    if (L->info == x) {
      elimOne3(L->next, x);
      delete L;
      L = L->next;
    } else {
      elimOne3(L->next, x);
    }
  }
}
//POST=(Lista(L) è come vLista(L) a parte i nodi con campo info = x, che, se esistono, vanno deallocato)