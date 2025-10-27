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
