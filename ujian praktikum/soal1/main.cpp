#include <iostream>
#include "main.h"
using namespace std;

int main() {
    int pilih;
    string nama;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. View\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertAkhir(nama);
                break;

            case 2:
                cout << "Nama yang mau dihapus: ";
                cin >> nama;
                deleteNama(nama);
                break;

            case 3:
                view();
                break;

            case 0:
                cout << "Keluar..." << endl;
                break;

            default:
                cout << "Menu nggak ada." << endl;
        }

    } while (pilih != 0);

    return 0;
}
