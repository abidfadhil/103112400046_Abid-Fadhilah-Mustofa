#include <iostream>
#include <string>

using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

void createQueue(QueueEkspedisi &Q);
bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void enQueue(QueueEkspedisi &Q, Paket dataBaru);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);