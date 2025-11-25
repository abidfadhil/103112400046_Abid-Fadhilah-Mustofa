#include "QueuePengiriman.h"
#include <iostream>
#include <iomanip>
using namespace std;

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

bool isEmpty(QueueEkspedisi Q) {
    return Q.Head == -1;
}

bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1;
}

void enQueue(QueueEkspedisi &Q, Paket dataBaru) {
    if (isFull(Q)) {
        cout << "Antrian penuh\n";
        return;
    }

    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = dataBaru;
    cout << "Paket " << dataBaru.KodeResi << " ditambahkan\n";
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "Menghapus paket " << Q.dataPaket[Q.Head].KodeResi << endl;

    if (Q.Head == Q.Tail) {
        Q.Head = -1;
        Q.Tail = -1;
    } else {
        for (int i = Q.Head; i < Q.Tail; i++) {
            Q.dataPaket[i] = Q.dataPaket[i+1];
        }
        Q.Tail--;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "Daftar Antrian:\n";
    cout << left << setw(5) << "No"
         << setw(10) << "Resi"
         << setw(15) << "Pengirim"
         << setw(8) << "Berat"
         << setw(10) << "Tujuan" << endl;

    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << left << setw(5) << (i+1)
             << setw(10) << Q.dataPaket[i].KodeResi
             << setw(15) << Q.dataPaket[i].NamaPengirim
             << setw(8) << Q.dataPaket[i].BeratBarang
             << setw(10) << Q.dataPaket[i].Tujuan << endl;
    }
}
