#include <iostream>
#include <string>
#include "pelajaran.h"
using namespace std;

int main() {
    string nama_pel = "Struktur Data";
    string kode_pel = "STD";

    pelajaran pel = create_pelajaran(nama_pel, kode_pel);
    tampil_pelajaran(pel);

    return 0;
}
