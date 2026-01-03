#include <iostream>
#include "Bst3.h"

using namespace std;

int main() {
    address root = Nil;

    tambahNode(root, 6);
    tambahNode(root, 4);
    tambahNode(root, 7);
    tambahNode(root, 2);
    tambahNode(root, 5);
    tambahNode(root, 1);
    tambahNode(root, 3);

    cout << "Pre-Order : ";
    preorder(root);
    cout << endl;

    cout << "Post-Order: ";
    postorder(root);
    cout << endl;

    return 0;
}
