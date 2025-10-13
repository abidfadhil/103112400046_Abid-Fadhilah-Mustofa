# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center"> Abid Fadhilah Mustofa- 103112400046 </p>

## Dasar Teori
Dalam ilmu komputer, tipe data abstrak adalah tipe data teoritis yang sebagian besar ditentukan oleh operasi dan bekerja di atasnya dan batasan yang berlaku.

Profesional menggambarkan tipe data abstrak sebagai ″model matematika″ untuk kelompok tipe data, atau sebagai ″nilai dengan operasi terkait″ yang tidak tergantung pada implementasi tertentu.


## Guided 

### 1. DENGN MODULAR
```C++
#include<iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m){
    cout<<"input NIM: ";
    cin>>m.nim;
    cout<<"input nilai 1: ";
    cin>>m.nilai1;
    cout<<"input nolai 2: ";
    cin>>m.nilai2;   
}

float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2)/2;
}
```
```C++
#include<iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m){
    cout<<"input NIM: ";
    cin>>m.nim;
    cout<<"input nilai 1: ";
    cin>>m.nilai1;
    cout<<"input nolai 2: ";
    cin>>m.nilai2;   
}

float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2)/2;
}
```

```C++
#include<iostream>
#include "mahasiswa.h"
#include<cstdlib>

using namespace std;

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout<<"rata-rata nilai adalah: "<<rata2(mhs);
    system("pause");

    return 0;
}
```
program ini di gunakan untuk memasukan data mahasiswa n menghitung rata" dari dua nilai

### 2. NON MODULAR

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

float rata2(mahasiswa &m) {
    return (float)(m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    
    cout << "rata - rata nilai adalah " << rata2(mhs)<< endl;
    system("pause");

    return 0;
} 
```

program ini mengambil data mahasiswa, lalu menghitung n menampilkan rata" dari 2 nilai yg diinput
## Unguided 

### 1. 

```C++
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
program ini berfungsi utk menghitung n menampilkan nilai akhir mahasiswa dengan input nilai
UTS, UAS dan tugas
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

program di atas merupakan program operasi matriks 3x3 yang menggunakan menu interaktif untuk memilih jenis operasi yang diinginkan. Pengguna dapat memilih antara penjumlahan, pengurangan, atau perkalian dua matriks yang ditentukan di awal program. Setiap operasi dilakukan menggunakan fungsi terpisah (jumlahmatriks, kurangmatriks, dan kalimatriks) yang masing-masing menghitung dan menampilkan hasilnya dalam bentuk matriks. Program akan terus menampilkan menu hingga pengguna memilih opsi keluar


### 2. 

```C++
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
```

```C++
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
```

```C++
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
inti program ini adalah menampilkan nama dan kode peljaran yg sudah dibuat menggunakan strukdat
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini menghitung luas dan keliling persegi panjang menggunakan konsep pointer, program menampilkan nilai panjang dan lebar, lalu pointer digunakan untuk mengakses alamat variabel tersebut untuk menghitung luas dan keliling. Setelah itu, nilai panjang dan lebar diubah melalui pointer, dan program kembali menghitung serta menampilkan luas dan keliling baru berdasarkan nilai yang telah diperbarui.

### 3. 

```C++
#include <iostream>
using namespace std;

void tampil_array(int arr[3][3]) {
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            cout << arr[a][b] << "\t";
        }
        cout << endl;
    }
}

void tukar_nilai(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int* ptr_a;
    int* ptr_b;

    ptr_a = &arr1[baris][kolom];
    ptr_b = &arr2[baris][kolom];

    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

int main() {
    int array_a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array_b[3][3] = {
        {99, 88, 77},
        {66, 55, 44},
        {33, 22, 11}
    };

    cout << "--- kondisi awal ---" << endl;
    cout << "isi array a:" << endl;
    tampil_array(array_a);

    cout << "\nisi array b:" << endl;
    tampil_array(array_b);

    int baris = 1;
    int kolom = 1;

    tukar_nilai(array_a, array_b, baris, kolom);

    cout << "\n--- setelah ditukar pada posisi [" << baris << "][" << kolom << "] ---" << endl;
    cout << "isi array a:" << endl;
    tampil_array(array_a);

    cout << "\nisi array b:" << endl;
    tampil_array(array_b);

}
inti program ini menampilkan dua array n menukar niai pada posisi tertentu di antara keduanya dgn menggunaka pointer
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] https://urlwebsite.com/blog/abstract-data-type/ 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
