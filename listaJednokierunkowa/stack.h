#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Stack operations
StackNode* stack_push(StackNode* top, int value);
StackNode* stack_pop(StackNode* top, int* value);
void stack_print(StackNode* top);
void stack_clear(StackNode** top);

#endif