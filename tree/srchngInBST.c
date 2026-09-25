//iterative method

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data){
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}
struct node *searchIter(struct node *root,int key){
    while(root != NULL){
        if(root->data == key){
            return root;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    return NULL;
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

    struct node *res = searchIter(p,2);
    if(res != NULL){
        printf("Found: %d\n",res->data);
    }
    else{
        printf("node not found\n");
    }

    return 0;
}