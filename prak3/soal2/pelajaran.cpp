#include "pelajaran.h"

pelajaran create_pelajaran(string nama_mapel, string kode_mapel) {
    pelajaran p;
    p.nama_mapel = nama_mapel;
    p.kode_mapel = kode_mapel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.nama_mapel << endl;
    cout << "nilai : " << pel.kode_mapel << endl;
}
