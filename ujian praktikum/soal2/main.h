#ifndef MAIN_H
#define MAIN_H

struct Node {
    int data;
    Node *prev;
    Node *next;
};

void insertAkhir(int x);
void deleteTerakhir();
void viewDepan();
void reverseList();

#endif
