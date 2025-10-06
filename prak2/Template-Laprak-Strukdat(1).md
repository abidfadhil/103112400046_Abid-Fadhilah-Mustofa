# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center"> Abid Fadhilah Mustofa- 103112400046 </p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. ...

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << " isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
program ini adlh latihan dasar input - output array dengan 2 jenis perulangan
### 2. ...

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){ // perulangan pertama buat baris
        for(int j = 0; j < 2; j++){ // ini buat kolom
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){ // baris
        for(int j = 0; j < 2; j++){ // kolom
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++){                        //perulangan baris
        for(int j = 0; j < 2; j++){                     //perulangan kolom
            for(int k = 0; k < 2; k++){         //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;
    
}```
perhitungan dasar oprasi aritmatika pada matriks 2 dimensi dalam c++
### 3. ...

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"eleem array ke-0"<< i+1<<"menggunakan pointer"<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<"menggunakan indeks"<<arr[i]<<endl;
    }
    return 0;
    
}```
program ini menampilkan isi array dengan 2 cara, yaitu: menggunakan pointer dan indeks
### 4.
```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }

 ```
 program ini menampilkan deret angka menggunakan tiga jenis perulangan (for, while, & do while)
## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int matriksa[3][3] = {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int matriksb[3][3] = {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

int hasil[3][3] = {0};

void jumlahmatriks(int matriksa[3][3], int matriksb[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = matriksa[i][j] + matriksb[i][j];
        }
    }
    cout << "hasil penjumlahan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kurangmatriks(int matriksa[3][3], int matriksb[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            hasil[i][j] = matriksa[i][j] - matriksb[i][j];
        }
    }
    cout << "hasil pengurangan: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

void kalimatriks(int matriksa[3][3], int matriksb[3][3], int hasil[3][3]){
    for (int i = 0; i < 3; i++){           
        for (int j = 0; j < 3; j++){        
            for (int k = 0; k < 3; k++){    
                hasil[i][j] += matriksa[i][k] * matriksb[k][j];
            }
        }
    }
    cout << "hasil perkalian: " << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n menu " << endl;
        cout << "1. penjumlahan matriks" << endl;
        cout << "2. pengurangan matriks" << endl;
        cout << "3. perkalian matriks" << endl;
        cout << "4. keluar" << endl;
        cout << "pilih operasi (1-4): ";
        cin >> pilihan;

         switch (pilihan) {
            case 1:
                jumlahmatriks(matriksa, matriksb, hasil);
                break;
            case 2:
                kurangmatriks(matriksa, matriksb, hasil);
                break;
            case 3:
                kalimatriks(matriksa, matriksb, hasil);
                break;
            case 4:
                cout << "keluar." << endl;
                break;
            default:
                cout << "tidak ada pilihan" << endl;
        }
        cout << endl; 
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

program di atas merupakan program operasi matriks 3x3 yang menggunakan menu interaktif untuk memilih jenis operasi yang diinginkan. Pengguna dapat memilih antara penjumlahan, pengurangan, atau perkalian dua matriks yang ditentukan di awal program. Setiap operasi dilakukan menggunakan fungsi terpisah (jumlahmatriks, kurangmatriks, dan kalimatriks) yang masing-masing menghitung dan menampilkan hasilnya dalam bentuk matriks. Program akan terus menampilkan menu hingga pengguna memilih opsi keluar


### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int kliling = 0;

    cout << "nilai awal" << endl;
    cout << "panjang: " << panjang << endl;
    cout << "lebar: " << lebar << endl;
    cout << endl;

    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    luas = (*ptrPanjang) * (*ptrLebar);
    kliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "hasil" << endl;
    cout << "luas persegi panjang: " << luas << endl;
    cout << "keliling persegi panjang: " << kliling << endl;
    cout << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    cout << "nilai setelah diubah" << endl;
    cout << "panjang baru: " << panjang << endl;
    cout << "lebar baru: " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    kliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "luas baru: " << luas << endl;
    cout << "keliling baru: " << kliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program ini menghitung luas dan keliling persegi panjang menggunakan konsep pointer, program menampilkan nilai panjang dan lebar, lalu pointer digunakan untuk mengakses alamat variabel tersebut untuk menghitung luas dan keliling. Setelah itu, nilai panjang dan lebar diubah melalui pointer, dan program kembali menghitung serta menampilkan luas dan keliling baru berdasarkan nilai yang telah diperbarui.

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
