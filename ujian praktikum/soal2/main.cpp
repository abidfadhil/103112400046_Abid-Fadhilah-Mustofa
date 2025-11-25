#include <iostream>
#include "main.h"
using namespace std;

int main() {
    int pilih, x;

    do {
        cout << "1 insert\n";
        cout << "2 delete\n";
        cout << "3 view\n";
        cout << "4 reverse & view\n";
        cout << "0 exit\n";
        cin >> pilih;

        if (pilih == 1) {
            cin >> x;
            insertAkhir(x);
        } 
        else if (pilih == 2) {
            deleteTerakhir();
        }
        else if (pilih == 3) {
            viewDepan();
        }
        else if (pilih == 4) {
            reverseList();
            viewDepan();
        }

    } while (pilih != 0);

    return 0;
}
