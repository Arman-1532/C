#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *s){
    if(s->top == s->size-1){
        return 1;
    }

    return 0;
}
int isEmpty(struct stack *s){
    if(s->top < 0){
        return 1;
    }

    return 0;
}
void push(struct stack *s, int value){
    if(!isFull(s)){
        s->top++;
        s->arr[s->top] = value;
        printf("%d has pushed\n",value);
    }
    else{
        printf("stack overflowed. %d cannot be inserted\n",value);
    }
}
int pop(struct stack *s){
    if(!isEmpty(s)){
        s->top--;
        return s->arr[s->top + 1];
    }
    else{
        printf("stack underflowed.\n");
        return 0;
    }
}
int peek(struct stack *s , int i){
    int index = s->top - i + 1;
    if(index < 0){
        printf("invalid position\n");
        return -1;
    }
    else{
        return s->arr[index];
    }
}
int stackTop(struct stack *s){
    return s->arr[s->top];
}
int stackBottom(struct stack *s){
    return s->arr[0];
}
int main(){
    struct stack *s;
    s->size = 6;
    s->top  = -1;
    s->arr = (int *) malloc( s->size * sizeof(int));

    if(!isFull(s) && isEmpty(s)){
        printf("start\n");
    }
    push(s,2);
    push(s,4);
    push(s,6);
    push(s,10);
    push(s,12);
    push(s,14);
    push(s,16);
    if(isFull(s) && !isEmpty(s)){
        printf("end\n");
    }

    printf("the top most value of this stack is %d\n", stackTop(s));
    printf("the bottom most value of this stack is %d\n",stackBottom(s));
    printf("%d has popped out\n",pop(s));

    for(int j = 1; j <= s->top + 1; j++){
        printf("the value of %dth position is %d\n", j, peek(s,j));
    }

    return 0;
}