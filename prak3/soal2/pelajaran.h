#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string nama_mapel;
    string kode_mapel;
};

pelajaran create_pelajaran(string nama_mapel, string kode_mapel);
void tampil_pelajaran(pelajaran pel);

#endif
