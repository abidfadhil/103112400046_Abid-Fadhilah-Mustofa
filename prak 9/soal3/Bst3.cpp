#include "Bst3.h"

address buatNode(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = Nil;
    p->right = Nil;
    return p;
}

void tambahNode(address &root, infotype x) {
    if (root == Nil) {
        root = buatNode(x);
    } else if (x < root->info) {
        tambahNode(root->left, x);
    } else if (x > root->info) {
        tambahNode(root->right, x);
    }
}

void inorder(address root) {
    if (root != Nil) {
        inorder(root->left);
        cout << root->info << " - ";
        inorder(root->right);
    }
}

void preorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(address root) {
    if (root != Nil) {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " - ";
    }
}
