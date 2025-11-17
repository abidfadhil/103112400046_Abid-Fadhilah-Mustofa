#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "Hello world!" << endl;
    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
