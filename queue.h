#include <big_int.h>
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

typedef struct Patient
{
    int exist;
    int spec;
    int local;
    int illness;
    int healthy;
    big_int *begin_t;
    big_int *end_t;
} Patient;

int Queue_Clear(Queue *queue);
//returns 0 if already empty, else 1

int Queue_isEmpty(Queue queue);
//returns 1 if empty, else 0

int Queue_Size(Queue queue);
//returns size of queue

int Queue_isFull(Queue queue);
//returns 1 if full, else 0

#define Enqueue(queue, item) _Generic(item, int: Enqueue_int, float: Enqueue_float, char: Enqueue_char, Patient: Enqueue_obj)(queue, item)
//Enqueue function accepts int, float and char types
//stores given item to queue's rear
//if successful returns 1, else 0

int Enqueue_float(Queue *queue, float item);

int Enqueue_int(Queue *queue, int item);

int Enqueue_char(Queue *queue, char item);

int Enqueue_obj(Queue *queue, Patient item);

#define Queue_Peek(queue, item) _Generic(item, int*: Queue_Peek_int, float*: Queue_Peek_float, char*: Queue_Peek_char, Patient*: Queue_Peek_obj)(queue, item)
//Peek function accepts int, float and char types
//stores to given item queue's front without removing it
//if successful returns 1, else 0

int Queue_Peek_float(Queue queue, float *item);

int Queue_Peek_int(Queue queue, int *item);

int Queue_Peek_char(Queue queue, char *item);

int Queue_Peek_obj(Queue queue, Patient *item);

#define Dequeue(queue, item) _Generic(item, int*: Dequeue_int, float*: Dequeue_float, char*: Dequeue_char, Patient*: Dequeue_obj)(queue, item)
//Dequeue function accepts int, float and char types
//stores to given item queue's front and removes it
//if successful returns 1, else 0

int Dequeue_float(Queue *queue, float *item);

int Dequeue_int(Queue *queue, int *item);

int Dequeue_char(Queue *queue, char *item);

int Dequeue_obj(Queue *queue, Patient *item);
