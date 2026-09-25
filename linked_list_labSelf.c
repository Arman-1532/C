#include<stdio.h>
#include<stdlib.h>

struct Node{
    int pid;
    int priority;
    struct Node *next;
};
struct Node *newNode(int pid, int priority){
    struct Node * ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->pid = pid;
    ptr->priority = priority;

    return ptr; 
}
struct Node *insert(struct Node *head, int pid, int priority){
    struct Node *q = newNode(pid, priority);
    if(head == NULL){
        return q;
    }
    struct Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = q;

    return head;
}
void traverse(struct Node *head){
    struct Node * ptr = head;
    while(ptr != NULL){
        printf("%d\t %d\n",ptr->pid, ptr->priority);
        ptr = ptr->next;
    }
}
int main(){

    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    head = NULL;
    FILE *fp;
    fp = fopen("text.txt", "r");
    int temp = 99999, test = 0;

    int numProcess;
    fscanf(fp,"%d", &numProcess);

    int i = 0, j = 0;
    int priority, pid;
    int temp_prio, temp_pid;
    while(i<numProcess){
        temp_prio = 9999;
        j = 0;
        FILE *fp2 = fopen("text.txt","r");
        int num;
        fscanf(fp2, "%d", &num);
        while(j<numProcess){
            fscanf(fp2,"%d", &pid);
            fscanf(fp2, "%d", &priority);
            if(priority < temp_prio && test < priority){
                temp_pid = pid;
                temp_prio = priority;
            }
            j++;
        }
        test = temp_prio;
        head = insert(head,temp_pid,temp_prio);
        i++;
        fclose(fp2);
    }
    traverse(head);
    fclose(fp);

    return 0;
} // nicher etar moto koreo kora jaay


// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     int item;        // Info (Item)
//     int priority;    // Prn (Item_Prn)
//     struct Node* link; // Link
// } Node;

// // Function to create a new node
// Node* createNode(int item, int priority) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->item = item;
//     newNode->priority = priority;
//     newNode->link = NULL;
//     return newNode;
// }

// // Function to insert an item into the priority queue
// Node* insertPriorityQ(Node* start, int item, int item_priority) {
//     Node* newNode = createNode(item, item_priority);

//     // 2. If Start is NULL, make newNode the start node and return
//     if (start == NULL) {
//         return newNode;
//     }

//     // 3. If priority of start node is less than item_priority, insert at the beginning
//     if (start->priority < item_priority) {
//         newNode->link = start;
//         return newNode;
//     }

//     // 4. Traverse the list and insert the newNode at the correct position
//     Node* save = start;
//     Node* ptr = start->link;

//     while (ptr != NULL) {
//         // 6. If priorities are equal, insert newNode after ptr
//         if (ptr->priority == item_priority) {
//             newNode->link = ptr->link;
//             ptr->link = newNode;
//             return start;
//         }
//         // 7. If the priority of ptr is less than item_priority, insert before ptr
//         else if (ptr->priority < item_priority) {
//             newNode->link = ptr;
//             save->link = newNode;
//             return start;
//         }
//         // 8. Move to the next node
//         save = ptr;
//         ptr = ptr->link;
//     }

//     // 9. Insert newNode at the end if it has the lowest priority
//     save->link = newNode;
//     return start;
// }

// // Function to display the priority queue
// void displayQueue(Node* start) {
//     Node* temp = start;
//     while (temp != NULL) {
//         printf("Item: %d, Priority: %d\n", temp->item, temp->priority);
//         temp = temp->link;
//     }
// }

// int main() {
//     Node* start = NULL;

//     start = insertPriorityQ(start, 10, 2);
//     start = insertPriorityQ(start, 20, 3);
//     start = insertPriorityQ(start, 30, 1);
//     start = insertPriorityQ(start, 40, 5);
//     start = insertPriorityQ(start, 50, 4);

//     printf("Priority Queue:\n");
//     displayQueue(start);

//     return 0;
// }
