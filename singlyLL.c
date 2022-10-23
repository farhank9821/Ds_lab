#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;
void insertAtFront()
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
    printf("Element inserted\n");
}
void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    printf("\nEnter value to insert: ");
    scanf("%d", &data);
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
    printf("Element inserted\n");
}
void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter value to insert and position to insert at: ");
    scanf("%d %d", &data, &pos);
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    printf("Element inserted\n");
}
void deleteFirst()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\nThe list is empty, choose a different option\n");
    }
    else
    {
        temp = start;
        start = start->link;
        free(temp);
        printf("\nElement deleted\n");
    }
}
void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
    {
        printf("\nThe list is empty, choose a different option\n");
    }
    else
    {
        temp = start;
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
        printf("\nElement deleted\n");
    }
}
void deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;
    if (start == NULL)
    {
        printf("\nThe list is empty, choose a different option\n");
    }
    else
    {
        printf("\nEnter the position to delete: ");
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }
        position = temp->link;
        temp->link = position->link;
        free(position);
        printf("Element deleted\n");
    }
}
void displayList()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\nThe list is empty, choose a different option\n");
    }
    else
    {
        temp = start;
        printf("\n%d <-- Start", temp->info);
        temp = temp->link;
        while ((temp->link) != NULL)
        {
            printf("\n%d", temp->info);
            temp = temp->link;
        }
        printf("\n%d <-- End\n", temp->info);
    }
}
int main()
{
    int choice;
    printf("MENU DRIVEN LINKED LIST\n");
    printf("\n1. Display current list\n2. Insert an element at the front\n3. Insert an element at the end\n4. Insert an element at a given position\n5. Delete the element at the front\n6. Delete the element at the end\n7. Delete the element at a given position\n8. Exit\n ");
    do
    {
        printf("\n Enter the Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            displayList();
            break;
        }
        case 2:
        {
            insertAtFront();
            break;
        }
        case 3:
        {
            insertAtEnd();
            break;
        }
        case 4:
        {
            insertAtPosition();
            break;
        }
        case 5:
        {
            deleteFirst();
            break;
        }
        case 6:
        {
            deleteEnd();
            break;
        }
        case 7:
        {
            deletePosition();
            break;
        }
        case 8:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("Invalid choice, try again");
        }
        }
    } while(choice != 8);
    return 0;
}