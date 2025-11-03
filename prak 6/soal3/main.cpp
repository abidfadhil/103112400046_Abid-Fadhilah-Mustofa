#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    infotype k1 = {"D001", "hitam", 90};
    infotype k2 = {"D002", "merah", 91};
    infotype k3 = {"D003", "biru", 92};
    infotype k4 = {"D004", "kuning", 90};

    insertLast(L, alokasi(k1));
    insertLast(L, alokasi(k2));
    insertLast(L, alokasi(k3));
    insertLast(L, alokasi(k4));

    string cari;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;

    deleteByNopol(L, cari);

    cout << endl;
    printInfo(L);

    return 0;
}
