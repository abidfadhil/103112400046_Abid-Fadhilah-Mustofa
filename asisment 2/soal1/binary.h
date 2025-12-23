#ifndef binary_h
#define binary_h

#include <iostream>
#include <string>

using namespace std;

struct node {
    string namamember;
    float beratbadan;
    string tiermember;
    node *left, *right;
};

bool isempty(node *root);
void createtree(node **root);
node* newnode(string nama, float berat, string tier);
void insertnode(node **root, string nama, float berat, string tier);
void inorder(node *root);
node* mostleft(node *root);
node* mostright(node *root);
void searchbyberatbadan(node *root, float berat);

#endif