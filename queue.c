#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

int Enqueue_float(Queue *queue, float item) //insert
{
    Node *node = NULL;
    node = malloc(sizeof(Node));
    if(node != NULL) //is allocating mem succesful
    {
        node->data = (float*) malloc(sizeof(float));
        *((float*)node->data) = item;
    }
    else
        return 0;

    if(queue->front == NULL)
    {
        queue->size = 1;
        queue->front = node;
        queue->rear = node;
        return 1;
    }
    else
    {
        ++(queue->size);
        queue->rear->next = node;
        queue->rear = node;
        return 1;
    }
}

int Enqueue_obj(Queue *queue, Patient item) //insert
{
    Node *node = NULL;
    node = malloc(sizeof(Node));
    if(node != NULL) //is allocating mem succesful
    {
        node->data = (Patient*) malloc(sizeof(Patient));
        *((Patient*)node->data) = item;
    }
    else
        return 0;

    if(queue->front == NULL)
    {
        queue->size = 1;
        queue->front = node;
        queue->rear = node;
        return 1;
    }
    else
    {
        ++(queue->size);
        queue->rear->next = node;
        queue->rear = node;
        return 1;
    }
}

int Enqueue_int(Queue *queue, int item) //insert
{
    Node *node = NULL;
    node = malloc(sizeof(Node));
    if(node != NULL) //is allocating mem succesful
    {
        node->data = (int*) malloc(sizeof(int));
        *((int*)node->data) = item;
    }
    else
        return 0;

    if(queue->front == NULL)
    {
        queue->size = 1;
        queue->front = node;
        queue->rear = node;
        return 1;
    }
    else
    {
        ++(queue->size);
        queue->rear->next = node;
        queue->rear = node;
        return 1;
    }
}

int Enqueue_char(Queue *queue, char item) //insert
{
    Node *node = NULL;
    node = malloc(sizeof(Node));
    if(node != NULL) //is allocating mem succesful
    {
        node->data = (char*) malloc(sizeof(char));
        *((char*)node->data) = item;
    }
    else
        return 0;

    if(queue->front == NULL)
    {
        queue->size = 1;
        queue->front = node;
        queue->rear = node;
        return 1;
    }
    else
    {
        ++(queue->size);
        queue->rear->next = node;
        queue->rear = node;
        return 1;
    }
}

int Queue_Peek_obj(Queue queue, Patient *item)
{
    if(queue.front == NULL)
        return 0;
    else
    {
        *item = *((Patient*)(queue.front)->data);
        return 1;
    }
}

int Queue_Peek_float(Queue queue, float *item)
{
    if(queue.front == NULL)
        return 0;
    else
    {
        *item = *((float*)(queue.front)->data);
        return 1;
    }
}

int Queue_Peek_int(Queue queue, int *item)
{
    if(queue.front == NULL)
        return 0;
    else
    {
        *item = *((int*)(queue.front)->data);
        return 1;
    }
}

int Queue_Peek_char(Queue queue, char *item)
{
    if(queue.front == NULL)
        return 0;
    else
    {
        *item = *((char*)(queue.front)->data);
        return 1;
    }
}

int Dequeue_obj(Queue *queue, Patient *item)
{
    if(Queue_Peek_obj(*queue, item) == 0)
        return 0;
    
    if(queue->front->next == NULL)
    {
        free(queue->front);
        queue->rear = NULL;
        queue->front = NULL;
        queue->size = 0;
        return 1;
    }
    else
    {
        Node *node = queue->front->next;
        free(queue->front);
        queue->front = node;
        --(queue->size);
        return 1;
    }
}

int Dequeue_float(Queue *queue, float *item)
{
    if(Queue_Peek_float(*queue, item) == 0)
        return 0;
    
    if(queue->front->next == NULL)
    {
        free(queue->front);
        queue->rear = NULL;
        queue->front = NULL;
        queue->size = 0;
        return 1;
    }
    else
    {
        Node *node = queue->front->next;
        free(queue->front);
        queue->front = node;
        --(queue->size);
        return 1;
    }
}

int Dequeue_int(Queue *queue, int *item)
{
    if(Queue_Peek_int(*queue, item) == 0)
        return 0;
    
    if(queue->front->next == NULL)
    {
        free(queue->front);
        queue->rear = NULL;
        queue->front = NULL;
        queue->size = 0;
        return 1;
    }
    else
    {
        Node *node = queue->front->next;
        free(queue->front);
        queue->front = node;
        --(queue->size);
        return 1;
    }
}

int Dequeue_char(Queue *queue, char *item) 
{
    if(Queue_Peek_char(*queue, item) == 0)
        return 0;
    
    if(queue->front->next == NULL)
    {
        free(queue->front);
        queue->rear = NULL;
        queue->front = NULL;
        queue->size = 0;
        return 1;
    }
    else
    {
        Node *node = queue->front->next;
        free(queue->front);
        queue->front = node;
        --(queue->size);
        return 1;
    }
}

int Queue_Size(Queue queue)
{
    if(queue.front == NULL)
    {
        return 0;
    }
    else
    {
        return queue.size;
    }
}

int Queue_isEmpty(Queue queue)
{
    if(queue.front == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int Queue_isFull(Queue queue)
{
    Node *node = malloc(sizeof(Node));
    if(node == NULL)
        return 1;
    else
    {
        free(node);
        return 0;
    }
}

int Queue_Clear(Queue *queue)
{
    if(queue->front == NULL)
        return 0;
    
    while(queue->front != NULL)
    {
        Node *node = queue->front->next;
        free(queue->front);
        queue->front = node;
    }
    return 1;
}
