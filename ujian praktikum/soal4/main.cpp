#include "QueuePengiriman.h"
#include <iostream>
#include <string>
using namespace std;

void inputDataPaketAwal(QueueEkspedisi &Q) {
    Paket p1 = {"123456", "Hutao", 14, "Sumeru"};
    enQueue(Q, p1);

    Paket p2 = {"234567", "Ayaka", 10, "Fontaine"};
    enQueue(Q, p2);

    Paket p3 = {"345678", "Bennet", 7, "Nattan"};
    enQueue(Q, p3);

    Paket p4 = {"456789", "Furina", 16, "Liyue"};
    enQueue(Q, p4);

    Paket p5 = {"567890", "Nefer", 6, "Inazuma"};
    enQueue(Q, p5);
}

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Buat antrian baru\n";
    cout << "2. Tambah paket (enqueue)\n";
    cout << "3. Hapus paket (dequeue)\n";
    cout << "4. Lihat antrian\n";
    cout << "5. Input data awal otomatis\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilih;
    bool sudahInputAwal = false;

    do {
        menu();
        cin >> pilih;

        switch (pilih) {
        case 1:
            createQueue(Q);
            sudahInputAwal = false;
            cout << "Antrian baru dibuat\n";
            break;

        case 2: {
            if (isFull(Q)) {
                cout << "Antrian penuh\n";
                break;
            }

            Paket x;
            cout << "Kode Resi: ";
            cin >> x.KodeResi;
            cout << "Nama Pengirim: ";
            cin.ignore();
            getline(cin, x.NamaPengirim);
            cout << "Berat: ";
            cin >> x.BeratBarang;
            cout << "Tujuan: ";
            cin >> x.Tujuan;

            enQueue(Q, x);
            break;
        }

        case 3:
            deQueue(Q);
            break;

        case 4:
            viewQueue(Q);
            break;

        case 5:
            if (!sudahInputAwal) {
                inputDataPaketAwal(Q);
                sudahInputAwal = true;

                cout << "\nAntrian setelah input data awal:\n";
                viewQueue(Q);

                cout << "\nMelakukan dequeue 1x...\n";
                deQueue(Q);

                cout << "\nAntrian setelah dequeue:\n";
                viewQueue(Q);
            } else {
                cout << "Data awal sudah pernah dimasukkan\n";
            }
            break;

        case 0:
            cout << "Program selesai\n";
            break;

        default:
            cout << "Pilihan tidak ada\n";
            break;
        }

        if (pilih != 0) {
            cout << "\nTekan ENTER untuk lanjut...";
            cin.ignore();
            cin.get();
        }

    } while (pilih != 0);

    return 0;
}
