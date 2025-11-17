#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, int x) {
    if (S.top < MAX - 1) {
        S.info[++S.top] = x;
    } else {
        cout << "Stack penuh!\n";
    }
}

int pop(Stack &S) {
    if (S.top >= 0) return S.info[S.top--];
    cout << "Stack kosong!\n";
    return -1;
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; --i) cout << S.info[i] << " ";
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0) push(temp, pop(S));
    S = temp;
}

void pushAscending(Stack &S, int x) {
    if (S.top >= MAX - 1) {
        cout << "Stack penuh!\n";
        return;
    }
    int i = S.top;
    S.top++;
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        i--;
    }
    S.info[i + 1] = x;
}