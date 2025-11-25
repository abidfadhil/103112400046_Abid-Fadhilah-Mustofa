#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa mhs) {
    if (isFull(S)) return;
    S.Top++;
    S.dataMahasiswa[S.Top] = mhs;
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) return;
    S.Top--;
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa mhs) {
    if (posisi < 1 || posisi > S.Top + 1) return;
    S.dataMahasiswa[posisi - 1] = mhs;
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    for (int i = S.Top; i >= 0; i--) {
        cout << "Nama : " << S.dataMahasiswa[i].Nama << endl;
        cout << "NIM : " << S.dataMahasiswa[i].NIM << endl;
        cout << "Tugas : " << S.dataMahasiswa[i].NilaiTugas << endl;
        cout << "UTS : " << S.dataMahasiswa[i].NilaiUTS << endl;
        cout << "UAS : " << S.dataMahasiswa[i].NilaiUAS << endl;
        cout << "---------------------\n";
    }
}

void SearchNilaiAkhir(StackMahasiswa &S, float min, float max) {
    for (int i = 0; i <= S.Top; i++) {
        float nilaiAkhir =
            0.2 * S.dataMahasiswa[i].NilaiTugas +
            0.4 * S.dataMahasiswa[i].NilaiUTS +
            0.4 * S.dataMahasiswa[i].NilaiUAS;

        if (nilaiAkhir >= min && nilaiAkhir <= max) {
            cout << "Nama : " << S.dataMahasiswa[i].Nama << endl;
            cout << "NIM : " << S.dataMahasiswa[i].NIM << endl;
            cout << "Nilai Akhir : " << nilaiAkhir << endl;
            cout << "---------------------\n";
        }
    }
}
