#include <iostream>
#include "main.h"
using namespace std;

Node *head = nullptr;
Node *tail = nullptr;

void insertAkhir(int x) {
    Node *baru = new Node();
    baru->data = x;
    baru->next = nullptr;
    baru->prev = tail;

    if (!head) head = baru;
    else tail->next = baru;
    tail = baru;
}

void deleteTerakhir() {
    if (!tail) return;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node *hapus = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete hapus;
    }
}

void viewDepan() {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node *temp = head, *swap = nullptr;

    while (temp) {
        swap = temp->prev;
        temp->prev = temp->next;
        temp->next = swap;
        temp = temp->prev;
    }

    if (swap) head = swap->prev;
}
