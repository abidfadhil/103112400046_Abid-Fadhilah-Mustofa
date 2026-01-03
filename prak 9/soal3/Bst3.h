#ifndef Bst3_H
#define Bst3_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

#define Nil NULL

address buatNode(infotype x);
void tambahNode(address &root, infotype x);
void inorder(address root);
void preorder(address root);
void postorder(address root);

#endif
