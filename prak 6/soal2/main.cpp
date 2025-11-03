#include "Doublylist.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;
    
    data = {"D008", "hijau", 90};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D001", "hitam", 55};
    P = alokasi(data);
    insertLast(L, P);

    data = {"D003", "putih", 99};
    P = alokasi(data);
    insertLast(L, P);

    string nopolCari = "D001";
    
    cout << "Masukkan Nomor Polisi yang dicari : " << nopolCari << endl; 
    
    P = findElm(L, nopolCari);

    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Nomor Polisi " << nopolCari << " tidak ditemukan.\n";
    }
    
    return 0;
}