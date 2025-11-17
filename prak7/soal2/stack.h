#ifndef STACK_H
#define STACK_H

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

void pushAscending(Stack &S, int x);

#endif