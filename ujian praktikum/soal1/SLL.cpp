#include <iostream>
#include "main.h"
using namespace std;

struct Node {
    string nama;
    Node *next;
};

Node *head = NULL;

// masukin nama ke belakang
void insertAkhir(string n) {
    Node *baru = new Node;
    baru->nama = n;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = baru;
    }
}

// hapus nama pertama yang ketemu
void deleteNama(string target) {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    // kalau yang mau dihapus itu head
    if (head->nama == target) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node *p = head;
    Node *prev = NULL;

    while (p != NULL && p->nama != target) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Nama nggak ada." << endl;
    } else {
        prev->next = p->next;
        delete p;
    }
}

// tampil semua nama
void view() {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    Node *p = head;
    while (p != NULL) {
        cout << p->nama;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}
