#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *creatingnode(int data){
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}
int main(){
    /*
    //creating node(root)
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = 1;
    p->left = NULL;
    p->right = NULL;

    //creating left child
    struct node *p1 = (struct node *) malloc(sizeof(struct node));
    p1->data = 2;
    p1->left = NULL;
    p1->right = NULL;

    //creating right child
    struct node *p2 = (struct node *) malloc(sizeof(struct node));
    p2->data = 3;
    p2->left = NULL;
    p2->right = NULL;

    //connecting those nodes
    p->left = p1;
    p->right = p2;
    */

    struct node *p = creatingnode(1);
    struct node *p1 = creatingnode(2);
    struct node *p2 = creatingnode(3);

    p->left = p1;
    p->right = p2;   
    
    return 0;
}