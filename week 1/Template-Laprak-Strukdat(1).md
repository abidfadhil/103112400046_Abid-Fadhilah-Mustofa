# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
C++ adalah bahasa pemrograman tingkat tinggi yang terkenal dengan efisiensinya. Bahasa ini diciptakan untuk melengkapi bahasa pemrograman C, dan mampu menangani aplikasi berperforma tinggi, seperti game dan sistem operasi


## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;
int main(){ 
int umur;
 cout << " masukan umur anda : ";
 cin >> umur;
 cout << " umur anda adalah " << umur << " tahun. " << end;
 return 0;
}
```
penjelasan singkat guided 1

### 2. ...

```C++
#include <iostream>
using namespace std;

int main (){
    int angka1, angka2;
    cout << "Masukan Angka 1"<< endl;
    cin >> angka1 ;
    cout << "Masukan angka 2" << endl;
    cin >> angka2;

    if (angka1 < angka2)
    {
        cout << angka1 << " Kurang dari " << angka2 << endl;
    }else {
        cout << angka1 << " Lebih dari " << angka2 << endl;

    }

    if (angka1 == angka2)
    {
        cout << angka1 <<" sama dengan " << angka2 << endl;
    } else  {
        cout << "Angka berbeda" << endl;
    }

    return 0;
    
    
}
```
penjelasan singkat guided 2

### 3. ...

```C++
#include <iostream>
using namespace std;

int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;   
    cout << "masukan pilihan: " << endl;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "penjumlahan: " << angka1 + angka2 << endl;
            cout << end break;
        case 2:
            cout << " pengurangan: " << angka1 - angka2 << endl;
            cout << end break;
        default:
            cout << "pilihan salah" << endl;
    }
```
penjelasan singkat guided 3

### Unguided 

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;
int main() {
    float angka1, angka2;
    cout << "masukkan angka1 :";
    cin >> angka1;
    cout << "masukkan angka2:";
    cin >> angka2;

    cout << "penjumlahan :" << angka1 + angka2 << endl;
    cout << "pengurangan :" << angka1 - angka2 << endl;
    cout << "perkalian :" << angka1 * angka2 << endl;
    cout << "pembagian :" << angka1 / angka2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/week%201/Screenshot%20Output1.png)



penjelasan unguided 1 
program ini adalah sebuah kalkulator simple yang melakukan empat operasi dasar (tambah, kurang, kali, bagi) terhadap dua bilangan desimal yang diinput oleh user
### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;
int main() {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", 
                        "empat belas", "lima belas", "enam belas", 
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", 
                        "delapan puluh", "sembilan puluh"};

    int a;
    cout << "masukkan angka (0 - 100): ";
    cin >> a;

    cout << a << " : ";

    if (a == 0) {
        cout << "nol";
    } 
    else if (a == 100) {
        cout << "seratus";
    }
    else if (a < 10) {
        cout << satuan[a];
    }
    else if (a < 20) {
        cout << belasan[a - 10];
    }
    else {
        int puluh = a / 10;
        int sisa = a % 10;
        cout << puluhan[puluh];
        if (sisa != 0) {
            cout << " " << satuan[sisa];
        }
    }

    cout << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/week%201/Screenshot%20Output2.png)

penjelasan unguided 2
program ini digunakan untuk mengubah angka ke teks dalam bahasa Indonesia (0–100) dengan logika percabangan 
### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main(){
    int n; 
    int a = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)  
    {
        for (int j = i; j >= 1; j--) 
        {
            cout << j;
        }
        
        cout << "*";
        for (int j = 1; j <= i; j++)
        {
            cout << j ;
        }

        cout << endl;
        for (int j = 1; j <= a; j++) 
        {
           cout << " ";
        }
        a ++;

    }
    cout << "*";
    
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided3](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/week%201/Screenshot%20Output3.png)

penjelasan unguided 3
program ini menghasilkan pola cermin angka dengan bintang di tengah yang makin lama makin mennyudut ke bawah
## Kesimpulan
...

## Referensi
[1] https://www.hostinger.com/id/tutorial/bahasa-pemrograman-cpp?utm_medium=ppc&utm_campaign=Generic-Tutorials-DSA|NT:Se|LO:ID&gad_source=1&gad_campaignid=16000629991&gbraid=0AAAAADMy-hYitw0Nn4GuYaKjj_aBfTjcS&gclid=Cj0KCQjw3OjGBhDYARIsADd-uX5mJS8EpbeZSlIMlN6wdQnOfRadFvLHdkPmUPJSTym8uA36w9QwK_oaAoTwEALw_wcB
<br>