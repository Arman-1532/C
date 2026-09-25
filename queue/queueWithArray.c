#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Queue *q){
    if(q->r == q->size - 1){
        return 1;
    }

    return 0;
}
int isEmpty(struct Queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q, int value){
    if(isFull(q)){
        printf("queue ovreloaded\n");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
        printf("%d is enqueued\n",value);
    }
}
int dequeue(struct Queue *q){
    int value = -1;
    if(isEmpty(q)){
        printf("no elements to dequeue\n");
        return value;
    }
    else{
        q->f++;
        value = q->arr[q->f];
        printf("%d has dequeued\n", value);
        return value;
    }
}
int main(){
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    enqueue(q,10);
    enqueue(q,12);
    enqueue(q,14);
    enqueue(q,16);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    if(isFull(q)){
        printf("queue is full\n");
    }

    if(isEmpty(q)){
        printf("queue is empty\n");
    }

    free(q->arr);
    
    return 0;
}