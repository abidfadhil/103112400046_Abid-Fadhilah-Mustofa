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
