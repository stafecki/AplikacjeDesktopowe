#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Lista jednokierunkowa
Node* list_push_front(Node* head, int value);
Node* list_push_back(Node* head, int value);
Node* list_insert_before(Node* head, int target, int value);
Node* list_insert_after(Node* head, int target, int value);

Node* list_remove_front(Node* head);
Node* list_remove_back(Node* head);
Node* list_remove_value(Node* head, int value);
Node* list_remove_after(Node* head, int target);
Node* list_remove_before(Node* head, int target);


Node* list_find(Node* head, int value);
void list_print(Node* head);
void list_clear(Node** head);

#endif // LIST_H
