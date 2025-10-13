#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilai_akhir;
};

float hitung_nilai_akhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    mahasiswa data[10];
    int jumlah;

    cout << "masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    cout << "\ninput data mahasiswa\n";

    for (int a = 0; a < jumlah; a++) {
        cout << "\nmahasiswa ke-" << a + 1 << endl;

        cout << "nama: ";
        cin >> data[a].nama;

        cout << "nim: ";
        cin >> data[a].nim;

        cout << "nilai uts, uas, tugas: ";
        cin >> data[a].uts >> data[a].uas >> data[a].tugas;

        data[a].nilai_akhir = hitung_nilai_akhir(
            data[a].uts,
            data[a].uas,
            data[a].tugas
        );
    }

    cout << "\n\n=== data mahasiswa ===\n";

    for (int a = 0; a < jumlah; a++) {
        cout << "\nmahasiswa ke-" << a + 1 << endl;
        cout << "nama        : " << data[a].nama << endl;
        cout << "nim         : " << data[a].nim << endl;
        cout << "nilai akhir : " << data[a].nilai_akhir << endl;
    }

    return 0;
}
