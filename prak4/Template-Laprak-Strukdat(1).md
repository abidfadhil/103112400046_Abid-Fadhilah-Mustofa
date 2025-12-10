# <h1 align="center">Laporan Praktikum Modul 4 - singlylist  C++ (Bagian Pertama)</h1>
<p align="center"> Abid Fadhilah Mustofa- 103112400046 </p>

## Dasar Teori
Single Linked List adalah sebuah field pointer-nya hanya satu buah saja dan satu arah serta pada akhir node yang nodenya saling terhubung satu sama lain. Jadi Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list.
## Guided 

### 1. DENGN MODULAR
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{ 
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini dibuat untuk menyimpan dan menampilkan data mahasiswa menggunakan struktur linked list. Cara kerjanya dimulai dengan membuat list yang masih kosong, lalu program membuat beberapa node berisi nama, NIM, dan umur mahasiswa. Setelah itu, node-node tersebut dimasukkan ke dalam list, ada yang ditaruh di bagian awal, ada yang disisipkan di tengah setelah node tertentu, dan ada juga yang ditambahkan di bagian paling akhir. Setelah semua data dimasukkan, program menampilkan seluruh isi list dari awal sampai akhir. Intinya, program ini menunjukkan bagaimana cara membuat linked list, menambah data ke dalamnya, dan melihat isi datanya dengan cara yang sederhana.
### 2. NON MODULAR

```C++
// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai`
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
Program ini membuat dan mengelola single linked list yang berisi data mahasiswa seperti nama, NIM, dan umur Di dalamnya ada fitur untuk membuat list kosong, menambah node (di awal, setelah node tertentu, atau di akhir), menghapus node, menghitung jumlah data, sampai menghapus seluruh list Pada fungsi main, program membuat lima data mahasiswa, lalu memasukkannya ke dalam linked list dengan berbagai metode insert Setelah semua data berhasil dimasukkan, program menampilkan seluruh isi list secara berurutan program ini pada dasarnya menunjukkan cara kerja linked list mulai dari membuat node, menyambungkannya, sampai menampilkannya ke layar dengan cara yang sederhana.
```
### 1.

```C++
#include "singlyList.h"
#include <iostream>
using namespace std;
const address NIL = nullptr;

void CreateList(List& L) {
    L.First = NIL;
}
address Alokasi(Infotype X) {
    address P = new Elmlist;
    if (P != NIL) {
        P->info = X;
        P->next = NIL;
    }
    return P;
}
void DeAlokasi(address& P) {
    delete P;
    P = NIL;
}
void printInfo(List L) {
    address P = L.First;
    cout << "Isi List: ";
    if (P == NIL) {
        cout << "List Kosong (Empty)";
    } else {
        while (P != NIL) {
            cout << P->info << " ";
            P = P->next;
        }
    }
    cout << endl;
}
void insFirst(List& L, address P) {
    if (P != NIL) {
        P->next = L.First;
        L.First = P;
    }
}
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

typedef int Infotype;
struct Elmlist;
typedef Elmlist* address;
struct Elmlist {
    Infotype info;
    address next;
};
struct List {
    address First;
};
void CreateList(List& L);
address Alokasi(Infotype X);
void DeAlokasi(address& P);
void printInfo(List L);
void insFirst(List& L, address P);
#endif
#include "singlyList.h"
#include <iostream>
const address NIL = nullptr;

int main() {
    List L;  
    address a1 = NIL;
    address a2 = NIL;
    address a3 = NIL;
    address a4 = NIL;
    address a5 = NIL;
   
    CreateList(L);
    a1 = Alokasi(2);
    insFirst(L, a1);
    a2 = Alokasi(0);
    insFirst(L, a2);
    a3 = Alokasi(8);
    insFirst(L, a3);
    a4 = Alokasi(12);
    insFirst(L, a4);
    a5 = Alokasi(9);
    insFirst(L, a5);
    printInfo(L); 
    return 0;
}
Program ini membuat sebuah singly linked list sederhana yang berisi angka-angka Pertama, list dibuat kosong dengan CreateList Setiap kali Alokasi dipanggil, program membuat node baru yang berisi sebuah angka Node-node ini kemudian dimasukkan ke bagian depan list menggunakan insFirst, jadi setiap data baru otomatis berada di posisi pertama Setelah semua angka (9, 12, 8, 0, 2) dimasukkan, fungsi printInfo menampilkan isi list dari awal sampai akhir Program ini menunjukkan cara dasar membuat linked list, menambah node di depan, dan mencetak semua isinya.

```
### Output Unguided 1 :

##### Output 1
![output_unguided1](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak4/output_soal1.jpg)


program di atas merupakan program operasi matriks 3x3 yang menggunakan menu interaktif untuk memilih jenis operasi yang diinginkan. Pengguna dapat memilih antara penjumlahan, pengurangan, atau perkalian dua matriks yang ditentukan di awal program. Setiap operasi dilakukan menggunakan fungsi terpisah (jumlahmatriks, kurangmatriks, dan kalimatriks) yang masing-masing menghitung dan menampilkan hasilnya dalam bentuk matriks. Program akan terus menampilkan menu hingga pengguna memilih opsi keluar


### 2. 

```C++
#include "singlyList.h"
#include <iostream>

using namespace std;

const address NIL = nullptr;
void CreateList(List& L) {
    L.First = NIL;
}
address Alokasi(Infotype X) {
    address P = new Elmlist;
    if (P != NIL) {
        P->info = X;
        P->next = NIL;
    }
    return P;
}
void DeAlokasi(address& P) {
    delete P;
    P = NIL;
}
void insFirst(List& L, address P) {
    if (P != NIL) {
        P->next = L.First;
        L.First = P;
    }
}
void printInfo(List L) {
    address P = L.First;
    while (P != NIL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
address Search(List L, Infotype X) {
    address P = L.First;
    while (P != NIL && P->info != X) {
        P = P->next;
    }
    return P;
}
void delFirst(List& L, address& P) {
    P = L.First;
    if (P != NIL) {
        L.First = P->next;
        P->next = NIL; 
    }
}
void delLast(List& L, address& P) {
    address Last = L.First;
    address Prec = NIL;

    if (Last == NIL) { 
        P = NIL;
        return;
    } else if (Last->next == NIL) { 
        P = Last;
        L.First = NIL;
    } else {
        while (Last->next != NIL) {
            Prec = Last;
            Last = Last->next;
        }
        P = Last;
        Prec->next = NIL;
    }
    P->next = NIL;
}
void delAfter(List& L, address Prec, address& P) {
    if (Prec != NIL && Prec->next != NIL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NIL;
    } else {
        P = NIL; 
    }
}
int nbList(List L) {
    address P = L.First;
    int count = 0;
    while (P != NIL) {
        count++;
        P = P->next;
    }
    return count;
}
void delList(List& L) {
    address P;
    while (L.First != NIL) {
        delFirst(L, P);
        DeAlokasi(P);
    }
}
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;
typedef int Infotype;
struct Elmlist;
typedef Elmlist* address;
struct Elmlist {
    Infotype info;
    address next;
};
struct List {
    address First;
};
void CreateList(List& L);
address Alokasi(Infotype X);
void DeAlokasi(address& P);
void printInfo(List L);
void insFirst(List& L, address P);
address Search(List L, Infotype X);
void delFirst(List& L, address& P);
void delLast(List& L, address& P);
void delAfter(List& L, address Prec, address& P);
int nbList(List L);
void delList(List& L);

#endif
#include <iostream>
#include "singlyList.h" 

using namespace std;

const address NIL = nullptr;

int main() {
    List L;
    address p_del = NIL;
    address Prec = NIL;
    
    CreateList(L);
    insFirst(L, Alokasi(2));
    insFirst(L, Alokasi(0));
    insFirst(L, Alokasi(8));
    insFirst(L, Alokasi(12));
    insFirst(L, Alokasi(9));
    delFirst(L, p_del);
    DeAlokasi(p_del);
    p_del = NIL; 
    delLast(L, p_del);
    DeAlokasi(p_del);
    p_del = NIL;
    Prec = Search(L, 12);
    delAfter(L, Prec, p_del);
    DeAlokasi(p_del);
    p_del = NIL;

    printInfo(L); 
    cout << "Jumlah node : " << nbList(L) << endl;
    delList(L);
    cout << "=== List Berhasil Terhapus ===" << endl; 
    cout << "Jumlah node : " << nbList(L) << endl;
    
    return 0;
}
Program ini membuat dan mengelola single linked list berisi angka Pertama list dibuat kosong, lalu beberapa angka dimasukkan ke bagian depan list (9, 12, 8, 0, 2) Setelah itu, program menghapus elemen pertama, menghapus elemen terakhir, dan menghapus elemen setelah angka 12. Program kemudian menampilkan isi list yang tersisa, menghitung jumlah nodenya, dan di akhir seluruh isi list dihapus sampai kosong Program ini intinya menunjukkan cara menambah, mencari, menghapus, dan menampilkan data pada linked list secara sederhana.
```
### Output Unguided 2 :

##### Output 1
![output _unguaided 2](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak4/output_soal2.jpg)


### 3. 

```C++

```
### Output Unguided 3 :

##### Output 1

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
