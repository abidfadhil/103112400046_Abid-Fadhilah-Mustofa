#include "binary.h"

int main() {
    node *root;
    createtree(&root);

    insertnode(&root, "rizkina azizah", 60, "basic");
    insertnode(&root, "hakan ismail", 50, "bronze");
    insertnode(&root, "olivia saevali", 65, "silver");
    insertnode(&root, "felix pedrosa", 47, "gold");
    insertnode(&root, "gamel al ghifari", 56, "platinum");
    insertnode(&root, "hanif al faiz", 70, "basic");
    insertnode(&root, "mutiara fauziah", 52, "bronze");
    insertnode(&root, "davi ilyas", 68, "silver");
    insertnode(&root, "abdad mubarok", 81, "gold");

    cout << "== traversal inorder ==" << endl;
    inorder(root);
    cout << endl << endl;

    searchbyberatbadan(root, 70);

    return 0;
}