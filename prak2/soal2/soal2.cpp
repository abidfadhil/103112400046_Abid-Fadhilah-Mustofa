#include <iostream>
using namespace std;

int main() {
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int kliling = 0;

    cout << "nilai awal" << endl;
    cout << "panjang: " << panjang << endl;
    cout << "lebar: " << lebar << endl;
    cout << endl;

    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    luas = (*ptrPanjang) * (*ptrLebar);
    kliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "hasil" << endl;
    cout << "luas persegi panjang: " << luas << endl;
    cout << "keliling persegi panjang: " << kliling << endl;
    cout << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << "nilai setelah diubah" << endl;
    cout << "panjang baru: " << panjang << endl;
    cout << "lebar baru: " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    kliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "luas baru: " << luas << endl;
    cout << "keliling baru: " << kliling << endl;

    return 0;
}
