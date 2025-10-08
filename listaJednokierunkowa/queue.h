#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// queue
void queue_init(Queue* q);
void queue_clear(Queue* q);
void queue_enqueue(Queue* q, int value);
int queue_dequeue(Queue* q, int* value);
void queue_print(const Queue* q);

#endif#pragma once
