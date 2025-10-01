#include<stdio.h>
#include<locale.h>
#include "list.h"
#include "stack.h"
int main() {
    setlocale(LC_ALL, "");

    // list
    Node* list = NULL;

    printf("Dodajê na koniec: 1, 2, 3\n");
    list = list_push_back(list, 1);
    list = list_push_back(list, 2);
    list = list_push_back(list, 3);
    list_print(list);

    printf("Dodajê na pocz¹tek: 0\n");
    list = list_push_front(list, 0);
    list_print(list);

    printf("Dodajê na koniec: 4\n");
    list = list_push_back(list, 4);
    list_print(list);

    printf("Dodajê po elemencie 2 wartoœæ 99\n");
    list = list_insert_after(list, 2, 99);
    list_print(list);

    printf("Dodajê przed elementem 3 wartoœæ 77\n");
    list = list_insert_before(list, 3, 77);
    list_print(list);

    printf("Usuwam pierwszy element\n");
    list = list_remove_front(list);
    list_print(list);

    printf("Usuwam ostatni element\n");
    list = list_remove_back(list);
    list_print(list);

    printf("Usuwam element o wartoœci 99\n");
    list = list_remove_value(list, 99);
    list_print(list);

    printf("Usuwam element po 2 (czyli powinien znikn¹æ 77)\n");
    list = list_remove_after(list, 2);
    list_print(list);

    printf("Usuwam element przed 2\n");
    list = list_remove_before(list, 2);
    list_print(list);

    printf("Wyszukujê element o wartoœci 2\n");
    Node* found = list_find(list, 2);
    if (found)
        printf("Znaleziono: %d\n", found->data);
    else
        printf("Nie znaleziono!\n");

    printf("Wyszukujê element o wartoœci 123\n");
    found = list_find(list, 123);
    if (found)
        printf("Znaleziono: %d\n", found->data);
    else
        printf("Nie znaleziono!\n");

    printf("Czyszczê listê:\n");
    list_clear(&list);
    list_print(list);

    //stack
    StackNode* stack = NULL;
    stack = stack_push(stack, 1);
    stack = stack_push(stack, 2);
    stack = stack_push(stack, 3);

    stack = stack_pop(stack, 3);

    stack_print(stack);

    stack_clear(&stack);
    return 0;
}