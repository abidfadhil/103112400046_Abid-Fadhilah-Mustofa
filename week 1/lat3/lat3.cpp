#include <iostream>
using namespace std;

int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;   
    cout << "masukan pilihan: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan: " << angka1 + angka2 << endl;
            cout << end break;
        case 2:
            cout << " pengurangan: " << angka1 - angka2 << endl;
            cout << end break;
        default:
            cout << "pilihan salah" << endl;
    }