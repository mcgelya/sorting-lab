struct QueueNode {           // элемент очереди
    struct QueueNode *next;  // элемент после
    int val;                 // значение
};

struct Queue {                       // сама очередь
    struct QueueNode *front, *back;  // первый и послдений элемент
};

void push(struct Queue *q, int x);  // в конец
void pop(struct Queue *q);          // удалить из начала
int top(struct Queue *q);           // первый элемент
