#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }

    return 0;
} 
int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    
    return 0;
}
int main(){
    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    // checking emptiness
    if(isEmpty(s)){
        printf("no element has stored yet\n");
    }
    else{
        printf("theres some elements in this stack\n");
    }

    s->arr[0] = 1;
    s->top++;

    s->arr[1] = 2;
    s->top++;

    s->arr[2] = 3;
    s->top++;
    
    s->arr[3] = 4;
    s->top++;

    s->arr[4] = 5;
    s->top++;

    s->arr[5] = 6;
    s->top++;
    
    if(isFull(s)){
        printf("this stack is full now\n");
    }
    else{
        printf("this stack is not full yet\n");
    }

    return 0;
}