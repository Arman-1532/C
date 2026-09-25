#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int pid;
    int priority;
    struct Node* next;
} Node;

Node* createNode(int pid, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->pid = pid;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int pid, int priority) {
    Node* newNode = createNode(pid, priority);
    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d %d\n", current->pid, current->priority);
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    int numProcesses;
    fscanf(file, "%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        int pid, priority;
        fscanf(file, "%d %d", &pid, &priority);
        insert(&head, pid, priority);
    }

    fclose(file);

    display(head);

    freeList(head);

    return 0;
}
