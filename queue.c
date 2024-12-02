#include <stdlib.h>

#include "queue.h"

void push(struct Queue *q, int x) {
    struct QueueNode *new_back = malloc(sizeof(struct QueueNode));
    new_back->next = NULL;
    new_back->val = x;
    if (q->back != NULL) {
        q->back->next = new_back;
    }
    if (q->front == NULL) {
        q->front = new_back;
    }
    q->back = new_back;
}

void pop(struct Queue *q) {
    struct QueueNode *front = q->front;
    if (front != NULL) {
        q->front = front->next;
        free(front);
    }
    if (q->front == NULL) {
        q->back = NULL;
    }
}

int top(struct Queue *q) {
    return q->front->val;
}
