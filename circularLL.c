#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* last = NULL;

void insertAtFront(int data)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(last == NULL) {
        temp -> info = data;
        temp -> next = temp;
        last = temp;
    }
    else {
        temp -> info = data;
        temp -> next = last->next;
        last -> next = temp;
    }
    printf("\nElement inserted\n");
}

void insertAtEnd(int data)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(last == NULL) {
        temp -> info = data;
        temp -> next = temp;
        last -> next = temp;
        last = temp;
    }
    else {
        temp -> info = data;
        temp -> next = last -> next;
        last -> next = temp;
        last = temp;
    }
    printf("\nElement inserted\n");
}

void deleteFirst()
{
    struct node* temp;
    if(last == NULL) {
        printf("\nThe list is empty\n");
    }
    else {
        temp = last -> next;
        last -> next = temp -> next;
        free(temp);
        printf("\nElement deleted\n");
    }
}

void deleteLast()
{
    struct node* temp;
    if(last == NULL) {
        printf("\nThe list is empty\n");
    }
    else {
        temp = last -> next;
        while(temp -> next != last) {
            temp = temp -> next;
        }
        temp -> next = last -> next;
        last = temp;
        printf("\nElement deleted\n");
    }
}

void displayList()
{
    if(last == NULL) {
        printf("\nThe list is empty\n");
    }
    else {
        struct node* temp;
        temp = last -> next;
        do {
            printf("\n%d", temp -> info);
            temp = temp -> next;
        } while(temp != last -> next);
        printf("\n%d <- Traversal has traced back to the first node\n", temp -> info);
    }
}

int main() {
    int choice, data;
    printf("MENU DRIVEN CIRCULAR LINKED LIST\n");
    while(1) {
        printf("\nChoose an option:\n1. Display current list\n2. Insert an element at the front\n3. Insert an element at the end\n4. Delete the first element\n5. Delete the last element\n6. Exit\n\nYour choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                displayList();
                break;
            }
            case 2: {
                printf("Enter value to be inserted: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            }
            case 3: {
                printf("Enter value to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            }
            case 4: {
                deleteFirst();
                break;
            }
            case 5: {
                deleteLast();
                break;
            }
            case 6: {
                
                exit(0);
            }
            default: {
                printf("Invalid choice");
            }
        }
    }
    return 0;
}