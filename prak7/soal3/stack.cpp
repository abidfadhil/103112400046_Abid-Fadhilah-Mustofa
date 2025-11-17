#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack Penuh!" << endl;
    } else {
        S.info[++S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        return Nil;
    }
    return S.info[S.top--];
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack A, B;
    CreateStack(A);
    CreateStack(B);

    while (!isEmpty(S)) push(A, pop(S));
    while (!isEmpty(A)) push(B, pop(A));
    while (!isEmpty(B)) push(S, pop(B));
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x)
        push(temp, pop(S));

    push(S, x);

    while (!isEmpty(temp))
        push(S, pop(temp));
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
    }
}
