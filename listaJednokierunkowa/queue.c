#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(Queue* q) {
    q->front = q->rear = NULL;
}

void queue_enqueue(Queue* q, int value) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = value;
    node->next = NULL;
    if (!q->rear) {
        q->front = q->rear = node;
    }
    else {
        q->rear->next = node;
        q->rear = node;
    }
}

int queue_dequeue(Queue* q, int* value) {
    if (!q->front) return 0;
    QueueNode* tmp = q->front;
    *value = tmp->data;
    q->front = tmp->next;
    if (!q->front) q->rear = NULL;
    free(tmp);
    return 1;
}

void queue_clear(Queue* q) {
    QueueNode* curr = q->front;
    while (curr) {
        QueueNode* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    q->front = q->rear = NULL;
}

void queue_print(const Queue* q) {
    QueueNode* curr = q->front;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}