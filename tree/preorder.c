#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *creatingNode(int data){
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}
void preorder(struct node *root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    struct node *p = creatingNode(4);
    struct node *p1 = creatingNode(1);
    struct node *p2 = creatingNode(6);
    struct node *p3 = creatingNode(5);
    struct node *p4 = creatingNode(2);
    
    /*
         4
         /\
        1  6
        /\
       5  2      */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preorder(p);

    return 0;
}