#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node *create(){
    int x;
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &x);
    if(x == -1){
        return 0;
    }
    else{
        newnode-> data = x;
        printf("Enter the left child of %d ", x);
        newnode -> left = create();
        printf("Enter the right child of %d ", x);
        newnode -> right = create();
        return newnode;
    }
}
int main(void){
    node *root;
    root = 0;
    root = create();

    return 0;
}