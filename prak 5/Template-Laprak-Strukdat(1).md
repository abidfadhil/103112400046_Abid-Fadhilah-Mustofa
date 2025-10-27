# <h1 align="center">Laporan Praktikum Modul 5 - singly linked list (Bagian kedua)</h1>
<p align="center"> Abid Fadhilah Mustofa- 103112400046 </p>

## Dasar Teori
Searching adalah proses menemukan elemen tertentu dalam sebuah struktur data, seperti array, list, atau database. Ada beberapa algoritma pencarian yang umum digunakan, di antaranya:

Linear Search: Algoritma ini bekerja dengan memeriksa setiap elemen dalam daftar satu per satu hingga menemukan elemen yang dicari. Meskipun sederhana, Linear Search memiliki kompleksitas waktu O(n), yang membuatnya kurang efisien untuk dataset yang besar.
Binary Search: Algoritma ini lebih efisien dengan kompleksitas waktu O(log n). Binary Search hanya dapat digunakan pada data yang sudah terurut. Algoritma ini membagi daftar menjadi dua bagian setiap kali iterasi, sehingga mengurangi jumlah perbandingan yang diperlukan.


## Guided 

### 1. DENGN MODULAR
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif

#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}
```
Dari program ini bisa disimpulkan kalau linked list adalah cara menyimpan data yang lebih fleksibel dibandingkan array, karena kita bisa menambah, menghapus, dan mengubah data kapan saja tanpa harus mengatur ulang seluruh data.
Melalui program ini juga terlihat bagaimana setiap data buah saling terhubung lewat node, sehingga proses pengelolaan datanya jadi lebih mudah dan efisien.

### 2. NON MODULAR

```C++
#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi binary search untuk linked list (data harus terurut)
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* binarySearch(Node* head, int key) {
    int length = getLength(head);      // Hitung panjang list
    int left = 0;
    int right = length - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Cari posisi tengah
        
        // Traverse ke posisi mid
        Node* temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        if(temp->data == key) {           // Jika ditemukan
            return temp;
        }
        else if(temp->data < key) {       // Cari di bagian kanan
            left = mid + 1;
        }
        else {                            // Cari di bagian kiri
            right = mid - 1;
        }
    }
    return nullptr;                       // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan elemen terurut ke linked list (penting untuk binary search!)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    int key = 30;  // Nilai yang dicari
    Node* result = binarySearch(head, key); // Panggil fungsi binary search

    if(result != nullptr) {
        cout << "Nilai " << key << " ditemukan dalam linked list." << endl;
    } else {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list." << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi linear search untuk mencari nilai dalam linked list
// Parameter: head (pointer awal list), key (nilai yang dicari)
// Return: pointer ke node jika ditemukan, nullptr jika tidak
Node* linearSearch(Node* head, int key) {
    Node* current = head;              // Mulai dari node pertama
    while (current != nullptr) {       // Traverse seluruh list
        if (current->data == key) {    // Jika data ditemukan
            return current;            // Kembalikan pointer node tersebut
        }
        current = current->next;       // Pindah ke node berikutnya
    }
    return nullptr;                    // Tidak ditemukan, return nullptr
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan beberapa elemen ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20); // Panggil fungsi linear search

  cout << (result ? "Found" : "Not Found") << endl; // Tampilkan hasil pencarian

    return 0;
}
```

Program ini menunjukkan dua cara mencari data di linked list.
Linear search mencari satu per satu dari awal sampai ketemu, sedangkan binary search membagi data jadi dua bagian dan mencari di bagian yang sesuai.
Linear search lebih sederhana, tapi binary search lebih cepat kalau datanya sudah terurut.
## Unguided 

### 1. 

```C++
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void append(node*& head, int value) {
    node* newnode = new node{value, nullptr};
    if (!head) head = newnode;
    else {
        node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newnode;
    }
}

void printlist(node* head) {
    cout << "linked list yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

node* getmiddle(node* start, node* end) {
    if (!start) return nullptr;
    node* slow = start;
    node* fast = start->next;
    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

node* binarysearch(node* head, int key) {
    node* start = head;
    node* end = nullptr;
    int step = 1;

    cout << "\nproses pencarian:\n";
    do {
        node* mid = getmiddle(start, end);
        if (!mid) {
            cout << "tidak ada elemen tersisa\n";
            return nullptr;
        }

        cout << "iterasi " << step++ << ": mid = " << mid->data << " (indeks tengah)";
        if (mid->data == key) {
            cout << " - ditemukan!\n";
            return mid;
        } else if (mid->data < key) {
            cout << " -> cari di bagian kanan\n";
            start = mid->next;
        } else {
            cout << " -> cari di bagian kiri\n";
            end = mid;
        }
    } while (end == nullptr || end != start);

    cout << "tidak ada elemen tersisa\n";
    return nullptr;
}

int main() {
    node* head = nullptr;
    int data[] = {10, 20, 30, 40, 50, 60};
    for (int x : data) append(head, x);

    cout << "binary search pada linked list\n";
    printlist(head);

    int cari1 = 40;
    cout << "mencari nilai: " << cari1 << endl;
    node* hasil1 = binarysearch(head, cari1);

    if (hasil1) {
        cout << "\nhasil: nilai " << hasil1->data << " ditemukan pada linked list!\n";
        cout << "alamat node: " << hasil1 << endl;
        cout << "data node: " << hasil1->data << endl;
        if (hasil1->next)
            cout << "node berikutnya: " << hasil1->next->data << endl;
        else
            cout << "node berikutnya: null" << endl;
    }

    int cari2 = 25;
    cout << "mencari nilai: " << cari2 << endl;
    node* hasil2 = binarysearch(head, cari2);

    if (!hasil2)
        cout << "\nhasil: nilai " << cari2 << " tidak ditemukan dalam linked list!\n";

    return 0;
}

Program ini mencari data di linked list yang sudah terurut dengan cara membagi data jadi dua bagian sampai nilai yang dicari ditemukan, cara ini lebih cepat dari mencari satu per satu, tapi sedikit lebih rumit karena linked list tidak punya indeks langsung seperti array.
```
### Output Unguided 1 :

##### Output 1
![output ung1](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak5/output%20ung1.jpg)


program di atas merupakan program operasi matriks 3x3 yang menggunakan menu interaktif untuk memilih jenis operasi yang diinginkan. Pengguna dapat memilih antara penjumlahan, pengurangan, atau perkalian dua matriks yang ditentukan di awal program. Setiap operasi dilakukan menggunakan fungsi terpisah (jumlahmatriks, kurangmatriks, dan kalimatriks) yang masing-masing menghitung dan menampilkan hasilnya dalam bentuk matriks. Program akan terus menampilkan menu hingga pengguna memilih opsi keluar


### 2. 

```C++
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void append(node*& head, int value) {
    node* newnode = new node{value, nullptr};
    if (!head) head = newnode;
    else {
        node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newnode;
    }
}

void printlist(node* head) {
    cout << "linked list yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

node* linearsearch(node* head, int key) {
    cout << "\nproses pencarian:\n";
    node* current = head;
    int pos = 1;

    while (current) {
        cout << "memeriksa node " << pos << ": " << current->data;
        if (current->data == key) {
            cout << " (sama) - ditemukan!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next;
        pos++;
    }

    cout << "tidak ada node lagi yang tersisa\n";
    return nullptr;
}

int main() {
    node* head = nullptr;
    int data[] = {10, 20, 30, 40, 50};
    for (int x : data) append(head, x);

    cout << "linear search pada linked list\n";
    printlist(head);

    int cari1 = 30;
    cout << "mencari nilai: " << cari1 << endl;
    node* hasil1 = linearsearch(head, cari1);

    if (hasil1) {
        cout << "\nhasil: nilai " << hasil1->data << " ditemukan pada linked list!\n";
        cout << "alamat node: " << hasil1 << endl;
        cout << "data node: " << hasil1->data << endl;
        if (hasil1->next)
            cout << "node berikutnya: " << hasil1->next->data << endl;
        else
            cout << "node berikutnya: null" << endl;
    }

    int cari2 = 25;
    cout << "mencari nilai: " << cari2 << endl;
    node* hasil2 = linearsearch(head, cari2);

    if (!hasil2)
        cout << "\nhasil: nilai " << cari2 << " tidak ditemukan dalam linked list!\n";

    return 0;
}

Program ini mencari data di dalam linked list dengan cara mengecek satu per satu dari awal sampai ketemu, cara ini akan lebih lama kalau datanya banyak karena harus dicek semuanya.
```
### Output Unguided 2 :

##### Output 1
![output ung2](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak5/output%20ung2.jpg)

Program ini menghitung luas dan keliling persegi panjang menggunakan konsep pointer, program menampilkan nilai panjang dan lebar, lalu pointer digunakan untuk mengakses alamat variabel tersebut untuk menghitung luas dan keliling. Setelah itu, nilai panjang dan lebar diubah melalui pointer, dan program kembali menghitung serta menampilkan luas dan keliling baru berdasarkan nilai yang telah diperbarui.

### 3. 

```C++

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] https://daffaireng123.medium.com/struktur-data-searching-b4578d84a160
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
