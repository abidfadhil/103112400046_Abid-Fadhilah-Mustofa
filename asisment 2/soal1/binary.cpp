#include "binary.h"

bool isempty(node *root) {
    return root == NULL;
}

void createtree(node **root) {
    *root = NULL;
}

node* newnode(string nama, float berat, string tier) {
    node *baru = new node();
    baru->namamember = nama;
    baru->beratbadan = berat;
    baru->tiermember = tier;
    baru->left = baru->right = NULL;
    return baru;
}

void insertnode(node **root, string nama, float berat, string tier) {
    if (isempty(*root)) {
        *root = newnode(nama, berat, tier);
    } else {
        if (berat < (*root)->beratbadan) {
            insertnode(&(*root)->left, nama, berat, tier);
        } else if (berat > (*root)->beratbadan) {
            insertnode(&(*root)->right, nama, berat, tier);
        }
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->beratbadan << " - ";
        inorder(root->right);
    }
}

node* mostleft(node *root) {
    if (root == NULL || root->left == NULL) return root;
    return mostleft(root->left);
}

node* mostright(node *root) {
    if (root == NULL || root->right == NULL) return root;
    return mostright(root->right);
}

void searchbyberatbadan(node *root, float berat) {
    node *curr = root;
    node *parent = NULL;

    while (curr != NULL && curr->beratbadan != berat) {
        parent = curr;
        if (berat < curr->beratbadan) curr = curr->left;
        else curr = curr->right;
    }

    if (curr == NULL) {
        cout << "data tidak ditemukan!" << endl;
        return;
    }

    cout << "data ditemukan didalam bst!" << endl;
    cout << " data node yang dicari " << endl;
    cout << "nama member : " << curr->namamember << endl;
    cout << "berat badan : " << curr->beratbadan << endl;
    cout << "tier member : " << curr->tiermember << endl;

    if (parent != NULL) {
        cout << "- data parent -" << endl;
        cout << "nama member : " << parent->namamember << endl;
        cout << "berat badan : " << parent->beratbadan << endl;
        cout << "tier member : " << parent->tiermember << endl;
        
        node *sibling = (parent->left == curr) ? parent->right : parent->left;
        if (sibling != NULL) cout << "- data sibling -nnama member : " << sibling->namamember << endl;
        else cout << "tidak memiliki sibling" << endl;
    }

    if (curr->left != NULL) {
        cout << "- data child kiri -" << endl;
        cout << "nama member : " << curr->left->namamember << "\nberat badan : " << curr->left->beratbadan << endl;
    }
    if (curr->right != NULL) {
        cout << "- data child kanan -" << endl;
        cout << "nama member : " << curr->right->namamember << "\nberat badan : " << curr->right->beratbadan << endl;
    }
}