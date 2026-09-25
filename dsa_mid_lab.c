#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int pid;
    int priority;
    struct Node *next;
}node;
node* insert(node *head,int pid, int priority){
    node *newnode = (node*) malloc(sizeof(node));
    newnode->pid = pid;
    newnode->priority = priority;
    newnode->next = head;
    head = newnode;

    return head;
}
node *sort(node *head){
    node *ptr1;
    node *ptr2 = NULL;
    int swapped;
    do{
        ptr1 = head;
        swapped = 0;
        while(ptr1->next != ptr2){
            if(ptr1->priority > ptr1->next->priority){

                int tmp_pid = ptr1->pid;
                int tmp_priority = ptr1->priority;

                ptr1->pid = ptr1->next->pid;
                ptr1->priority = ptr1->next->priority;

                ptr1->next->pid = tmp_pid;
                ptr1->next->priority = tmp_priority;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;

    }while(swapped);

    return head;
}
void display(node *head){
    while(head != NULL){
        printf("%d\t%d\n", head->pid,head->priority);
        head = head->next;
    }
    printf("\n");
}
int main(){
    FILE *fp = fopen("input.txt","r");
    int numberOfTest;
    fscanf(fp,"%d",&numberOfTest);
    node *head = (node*) malloc(sizeof(node));
    int pid,priority;

    for(int i=0;i<numberOfTest;i++){
        fscanf(fp,"%d",&pid);
        fscanf(fp,"%d",&priority);
        head = insert(head,pid,priority);
    }

    fclose(fp);
    display(head);
    head = sort(head);
    display(head);
}