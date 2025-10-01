#include "list.h"
#include "stdlib.h"
#include "stdio.h"

Node* list_push_front(Node* head, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = head;
	return node;
}

Node* list_push_back(Node* head, int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = NULL;
	if (!head) return node;
	Node* curr = head;
	while (curr->next) curr = curr->next;
	curr->next = node;
	return head;
}

Node* list_insert_before(Node* head, int target, int val) {
    if (!head) return NULL;
    if (head->data == target)
        return list_push_front(head, val);
    Node* prev = head;
    Node* curr = head->next;
    while (curr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return head;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = curr;
    prev->next = node;
    return head;
}

Node* list_insert_after(Node* head, int target, int val) {
    Node* curr = head;
    while (curr && curr->data != target)
        curr = curr->next;
    if (!curr) return head;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = curr->next;
    curr->next = node;
    return head;
}

Node* list_remove_front(Node* head) {
    if (!head) return NULL;
    Node* temp = head->next;
    free(head);
    return temp;
}

Node* list_remove_back(Node* head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
    return head;
}

Node* list_remove_value(Node* head, int value) {
    if (!head) return NULL;
    if (head->data == value)
        return list_remove_front(head);
    Node* prev = head;
    Node* curr = head->next;
    while (curr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return head;
    prev->next = curr->next;
    free(curr);
    return head;
}

Node* list_remove_after(Node* head, int target) {
    Node* curr = head;
    while (curr && curr->data != target)
        curr = curr->next;
    if (curr && curr->next) {
        Node* tmp = curr->next;
        curr->next = tmp->next;
        free(tmp);
    }
    return head;
}
Node* list_remove_before(Node* head, int target) {
    if (!head || !head->next) return head;
    if (head->next->data == target) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    Node* prev = head;
    Node* curr = head->next;
    Node* next = curr->next;
    while (next) {
        if (next->data == target) {
            prev->next = next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = next;
        next = next->next;
    }
    return head;
}

Node* list_find(Node* head, int value) {
    Node* curr = head;
    while (curr) {
        if (curr->data == value)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void list_print(Node* head) {
    Node* curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void list_clear(Node** head) {
    Node* curr = *head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}