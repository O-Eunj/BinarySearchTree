#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

struct Node;
typedef struct Node Node;

#define MAX_QUEUE 100

typedef struct {
    Node* data[MAX_QUEUE];
    int tail;
    int head;
    int size;
} Queue;

void init_queue(Queue* q);
bool empty_queue(Queue* q);
bool full_queue(Queue* q);
void push_queue(Queue* q, Node* value);
bool pop_queue(Queue* q, Node** value);

#endif
