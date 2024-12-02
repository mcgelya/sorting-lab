struct QueueNode {
    struct QueueNode *next;
    int val;
};

struct Queue {
    struct QueueNode *front, *back;
};

void push(struct Queue *q, int x);
void pop(struct Queue *q);
int top(struct Queue *q);
