# <h1 align="center">Laporan Praktikum Modul 8 - queue C++ </h1>
<p align="center"> Abid Fadhilah Mustofa- 103112400046 </p>

## Dasar Teori
Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah First In, First Out (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.

## Guided 

### 1. DENGN MODULAR
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```
Program ini bikin queue (antrian) pakai linked list, di mana data masuk dari belakang dan keluar dari depan. Ada fitur tambah (enqueue), hapus (dequeue), update posisi tertentu, dan cari data. Di main, program masukin angka 1-5 ke antrian, update beberapa posisi, lalu nampilin dan nyari datanya.
### 2. NON MODULAR

```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}
bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}
bool isFullQueue(Queue Q){
    if (Q.head == 0 && Q.tail == NMax - 1) {
        return true;
    }
    if (Q.tail + 1 == Q.head) {
        return true;
    }
    return false;
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
            Q.info[Q.tail] = x;
        }
    }
}
infotype dequeue(Queue &Q){
    infotype temp = UNDERFLOW_VALUE;   
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        temp = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = Nil;
            Q.tail = Nil;
        } else {
            Q.head = (Q.head + 1) % NMax;
        }
    }
    return temp;
}
void printInfo(Queue Q){   
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false; 
            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail) {
                    isActive = true;
                }
            } else {
                if (i >= Q.head || i <= Q.tail) {
                    isActive = true;
                }
            } 
            if (isActive) {
                cout << Q.info[i] << " ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 
const int UNDERFLOW_VALUE = -999; 

struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
Queue Q;
createQueue(Q);
cout<<"----------------------"<<endl;
cout<<" H - T \t | Queue info"<<endl;
cout<<"----------------------"<<endl;
printInfo(Q);
enqueue(Q,5); printInfo(Q);
enqueue(Q,2); printInfo(Q);
enqueue(Q,7); printInfo(Q);
dequeue(Q); printInfo(Q);
enqueue(Q,4); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
return 0;
}
Kode ini membuat queue (antrian) berbasis array melingkar Program bisa menambah data (enqueue), menghapus data (dequeue), mengecek apakah queue penuh atau kosong, dan menampilkan isi antrian Pada main, queue diisi beberapa angka, lalu sebagian dihapus, sambil setiap langkahnya ditampilkan perubahan posisi head-tail dan isi antriannya.
```
### 3. NON MODULAR

```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}

bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % NMax == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong !" << endl;
        return 0; 
    }

    infotype temp = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = (Q.head + 1) % NMax;
    }

    return temp;
}


void printInfo(Queue Q){
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false;

            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail)
                    isActive = true;
            } else {
                if (i >= Q.head || i <= Q.tail)
                    isActive = true;
            }

            if (isActive) cout << Q.info[i] << " ";
            else cout << "  ";
        }
        cout << endl;
    }
}
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 


struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
Program ini adalah queue circular berbasis array berukuran 5 yang menggunakan head dan tail untuk mengatur antrian Program mendukung operasi enqueue (menambah data), dequeue (menghapus data), serta pengecekan kondisi kosong dan penuh, lalu menampilkan isi queue untuk memperlihatkan perubahan antrian selama program dijalankan.
```
##### Output Unguaided 1 :

##### Output 1
![soal1](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak%208/soal1.jpg)


### 2. 

```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}
bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}
bool isFullQueue(Queue Q){
    if (Q.head == 0 && Q.tail == NMax - 1) {
        return true;
    }
    if (Q.tail + 1 == Q.head) {
        return true;
    }
    return false;
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
            Q.info[Q.tail] = x;
        }
    }
}
infotype dequeue(Queue &Q){
    infotype temp = UNDERFLOW_VALUE;   
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong (Underflow)!" << endl;
    } else {
        temp = Q.info[Q.head];
        
        if (Q.head == Q.tail) {
            Q.head = Nil;
            Q.tail = Nil;
        } else {
            Q.head = (Q.head + 1) % NMax;
        }
    }
    return temp;
}
void printInfo(Queue Q){   
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";    
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false; 
            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail) {
                    isActive = true;
                }
            } else {
                if (i >= Q.head || i <= Q.tail) {
                    isActive = true;
                }
            } 
            if (isActive) {
                cout << Q.info[i] << " ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 
const int UNDERFLOW_VALUE = -999; 

struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
Queue Q;
createQueue(Q);
cout<<"----------------------"<<endl;
cout<<" H - T \t | Queue info"<<endl;
cout<<"----------------------"<<endl;
printInfo(Q);
enqueue(Q,5); printInfo(Q);
enqueue(Q,2); printInfo(Q);
enqueue(Q,7); printInfo(Q);
dequeue(Q); printInfo(Q);
enqueue(Q,4); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
return 0;
}
Program ini adalah queue circular berbasis array yang bisa menambah (enqueue), menghapus (dequeue), dan menampilkan isi queue main menambahkan dan menghapus beberapa elemen untuk menunjukkan cara kerja antrian FIFO.
```
### Output Unguided 2 :

##### Output 1
![soal2](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak%208/soal2.jpg)


### 3. 

```C++
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

void createQueue(Queue &Q){
    Q.head = Nil;
    Q.tail = Nil;
    for (int i = 0; i < NMax; i++) {
        Q.info[i] = 0;
    }
}

bool isEmptyQueue(Queue Q){
    return (Q.head == Nil);
}

bool isFullQueue(Queue Q){
    return ((Q.tail + 1) % NMax == Q.head);
}

void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)) {
        cout << "Queue Penuh (Overflow)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % NMax;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)) {
        cout << "Queue Kosong !" << endl;
        return 0; 
    }

    infotype temp = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Nil;
        Q.tail = Nil;
    } else {
        Q.head = (Q.head + 1) % NMax;
    }

    return temp;
}


void printInfo(Queue Q){
    cout << setw(1) << Q.head << " - " << setw(1) << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i < NMax; i++) {
            bool isActive = false;

            if (Q.head <= Q.tail) {
                if (i >= Q.head && i <= Q.tail)
                    isActive = true;
            } else {
                if (i >= Q.head || i <= Q.tail)
                    isActive = true;
            }

            if (isActive) cout << Q.info[i] << " ";
            else cout << "  ";
        }
        cout << endl;
    }
}
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;
const int NMax = 5;
const int Nil = -1; 


struct Queue {
    infotype info[NMax];
    int head;
    int tail; 
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x); 
infotype dequeue(Queue &Q);
void printInfo(Queue Q); 

#endif
#include "queue.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
Program ini adalah queue circular berbasis array yang bisa menambah (enqueue), menghapus (dequeue), dan menampilkan elemen Queue menggunakan head dan tail untuk menandai posisi depan dan belakang main menunjukkan bagaimana elemen masuk dan keluar sesuai aturan FIFO Program juga menampilkan pesan saat queue kosong atau penuh agar pengguna tahu status antrian.
```
### Output Unguided 3 :

##### Output 1
![soal3](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak%208/soal3.jpg)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1]https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
