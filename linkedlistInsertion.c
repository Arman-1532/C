#include<stdio.h>
#include<stdlib.h>

struct Node{
        int data;
        struct Node *next;
    };

struct Node *insertionAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node *insertionAtIndex(struct Node *head,int data,int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next = ptr;

    return head;

}
void *insertionAtEnd(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next=ptr;

    return head;
}
struct Node *insertionAfterNode(struct Node *head,struct Node *node,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;

    return head;
}
void traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *forth = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node*)malloc(sizeof(struct Node));

    //link first and second nodes
    head->data = 0;
    head->next = second;

    //link second and third nodes
    second->data = 1;
    second->next = third;

    //link third and forth nodes
    third->data = 2;
    third->next = forth;

    //link forth and fifth nodes
    forth->data = 3;
    forth->next = fifth;

    //terminating linked  list
    fifth->data = 4;
    fifth->next = NULL;

    traversal(head);
    head=insertionAfterNode(head,second,-1);
    traversal(head);
}   