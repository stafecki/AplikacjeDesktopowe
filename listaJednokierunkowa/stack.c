#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

StackNode* stack_push(StackNode* top, int value) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = value;
    node->next = top;
    return node;
}

StackNode* stack_pop(StackNode* top, int* value) {
    if (!top) return NULL;
    *value = top->data;
    StackNode* next = top->next;
    free(top);
    return next;
}

void stack_print(StackNode* top) {
    StackNode* current = top;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void stack_clear(StackNode** top) {
    StackNode* current = *top;
    while (current) {
        StackNode* tmp = current;
        current = current->next;
        free(tmp);
    }
    *top = NULL;
}