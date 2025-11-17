# <h1 align="center">Laporan Praktikum Modul 7 - stuck C++ </h1>
<p align="center"> Abid Fadhilah Mustofa- 103112400046 </p>

## Dasar Teori
struktur data adalah suatu cara untuk menyimpan dan mengorganisir data dalam sebuah program komputer agar dapat diakses dan diproses dengan lebih efisien. Salah satu struktur data yang umum digunakan adalah stack atau tumpukan. Stack adalah struktur data linear yang bekerja berdasarkan prinsip LIFO (Last In First Out) atau yang artinya data yang terakhir dimasukkan ke dalam stack akan menjadi data yang pertama kali diambil atau dikeluarkan dari stack.

Stack biasanya digunakan dalam implementasi algoritma dan fungsi-fungsi matematis seperti konversi infix ke postfix, evaluasi ekspresi postfix, dan validasi tanda kurung pada ekspresi matematis. Stack juga sering digunakan dalam aplikasi yang membutuhkan manajemen tumpukan data seperti pengembangan sistem operasi, kompilator, dan perangkat lunak grafis.

## Guided 

### 1. DENGN MODULAR
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }

}
#ifndef STACK_H
#define STACK_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct node* address;

struct node{
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka); 
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update (stack &listStack, int posisi);
void view (stack listStack);
void searchData(stack listStack, int data);

#endif
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini membuat sebuah tumpukan (stack) yang cara kerjanya seperti menumpuk barang—barang yang terakhir ditaruh akan menjadi yang pertama diambil. Stack ini dibuat menggunakan linked list, di mana setiap data terhubung ke data berikutnya. Program memiliki beberapa fungsi, seperti menambah data ke atas tumpukan (push), mengambil data dari atas tumpukan (pop), mengubah data pada posisi tertentu, menampilkan isi tumpukan, dan mencari data tertentu. Di bagian utama program, dibuat lima data lalu semuanya dimasukkan ke dalam stack. Setelah itu dua data teratas dihapus, beberapa data diubah, dan program juga mengecek apakah data tertentu ada dalam stack. Intinya, program ini menunjukkan bagaimana stack bekerja menggunakan pointer dan node.
### 2. NON MODULAR

```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }

}
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
Program ini membuat sebuah stack (tumpukan data) menggunakan array dengan kapasitas 20 angka Stack bekerja seperti menumpuk barang: data yang terakhir dimasukkan akan menjadi yang pertama diambil Program memiliki fitur untuk mengecek apakah stack kosong atau penuh, menambah data (push), mengambil data teratas (pop), menampilkan seluruh isi stack, dan membalik urutan stack Pada bagian utama program, beberapa angka dimasukkan dan diambil dari stack sesuai urutan perintah, lalu isi stack ditampilkan Setelah itu, stack dibalik menggunakan stack sementara, dan hasil akhirnya ditampilkan lagi Secara singkat, program ini menunjukkan cara kerja dasar stack dan bagaimana data bisa diputar balik menggunakan operasi push dan pop.
```
### 1.

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, int x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!\n";
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}
#ifndef STACK_H
#define STACK_H

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
#include "stack.h"
#include <iostream>

using namespace std;

int main() 
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);

    push(S, 2);
    push(S, 3);
    pop(S);

    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}

Program ini menunjukkan cara kerja stack (tumpukan) dengan aturan LIFO, di mana data terakhir yang dimasukkan akan keluar lebih dulu Stack dibuat kosong dengan createStack, lalu angka-angka dimasukkan menggunakan push dan beberapa nilai diambil menggunakan pop Fungsi printInfo dipakai untuk menampilkan isi stack dari atas ke bawah Program juga memiliki fungsi balikStack yang membalik urutan isi stack dengan memindahkannya ke stack sementara Di dalam main, program memasukkan dan menghapus beberapa angka, menampilkan isi stack, membalik urutannya, lalu menampilkannya lagi Program ini intinya memperlihatkan proses menambah, mengambil, menampilkan, dan membalik data pada stack secara sederhana.

```
### Output Unguided 1 :

##### Output 1
![output_unguided1](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak7/soal1/soal1.jpg)

### 2. 

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, int x) {
    if (S.top < MAX - 1) {
        S.info[++S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) return S.info[S.top--];
    cout << "Stack kosong!\n";
    return -1;
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0) push(temp, pop(S));
    S = temp;
}

void pushAscending(Stack &S, int x) {
    if (S.top >= MAX - 1) {
        cout << "Stack penuh!\n";
        return;
    }
    int i = S.top;
    S.top++;
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        i--;
    }
    S.info[i + 1] = x;
}
#ifndef STACK_H
#define STACK_H

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

void pushAscending(Stack &S, int x);

#endif
#include "stack.h"
#include <iostream>

using namespace std;

int main() 
{
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}


Program ini menunjukkan cara kerja stack (tumpukan) dengan aturan LIFO, di mana data terakhir yang dimasukkan akan keluar lebih dulu Stack dibuat kosong dengan createStack, lalu angka-angka dimasukkan menggunakan push dan beberapa nilai diambil menggunakan pop Fungsi printInfo dipakai untuk menampilkan isi stack dari atas ke bawah Program juga memiliki fungsi balikStack yang membalik urutan isi stack dengan memindahkannya ke stack sementara Di dalam main, program memasukkan dan menghapus beberapa angka, menampilkan isi stack, membalik urutannya, lalu menampilkannya lagi Program ini intinya memperlihatkan proses menambah, mengambil, menampilkan, dan membalik data pada stack secara sederhana.
```
### Output Unguided 2 :

##### Output 1
![output _unguaided 2](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak7/soal2/soal2.jpg)


### 3. 

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        S.info[++S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        return Nil;
    }
    return S.info[S.top--];
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack A, B;
    CreateStack(A);
    CreateStack(B);

    while (!isEmpty(S)) push(A, pop(S));
    while (!isEmpty(A)) push(B, pop(A));
    while (!isEmpty(B)) push(S, pop(B));
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x)
        push(temp, pop(S));

    push(S, x);

    while (!isEmpty(temp))
        push(S, pop(temp));
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
    }
}
#ifndef STACK_H
#define STACK_H

#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "Hello world!" << endl;
    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

Program ini merupakan implementasi sederhana dari struktur data stack yang dibuat secara manual menggunakan array, di mana setiap operasinya—seperti push, pop, pengecekan kosong atau penuh, hingga mencetak isi stack—ditangani lewat fungsi terpisah agar lebih rapi dan mudah dipahami; selain itu, program ini juga menambahkan fitur untuk membalik isi stack serta memasukkan data secara ascending, dan di bagian utama (main) program hanya menerima input angka dari pengguna, menampilkannya sebagai stack, kemudian membalik urutannya, sehingga alurnya tetap sederhana dan jelas seperti program buatan mahasiswa pada umumnya.
```
### Output Unguided 3 :

##### Output 1
![output_unguaided 3](https://github.com/abidfadhil/103112400046_Abid-Fadhilah-Mustofa/blob/main/prak7/soal3/soal3.jpg)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] https://dosenit.com/ilmu-komputer/struktur-data-stack
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
