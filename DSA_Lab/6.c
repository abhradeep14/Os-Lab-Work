#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void insert(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }

    head = temp;
}

void delete(int data) {
    Node* temp = head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp == head) {
        head = temp->next;
    }

    free(temp);
}

void printList() {
    Node* node = head;

    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                printList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
