#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data){
    struct node *root = (struct node *) malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}
void *insert(struct node *root,int key){
    struct node *prev;
    while(root != NULL){
        prev = root;
        if(root->data == key){
            printf("%d cannot be inserted because its present in this tree\n",key);
            return NULL;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if(prev->data > key){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}
void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);
    /*
         5
         /\
        3  6
        /\
       2 4      */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p,1);

    inorder(p);

    return 0;
}