#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    newNode->next = head;

    head = newNode;
}

void pop()
{
  
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);

  
        temp = head;


        head = head->next;

        free(temp);
    }
}


void printList()
{
    struct node *temp = head;

 
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
   int choice;
   printf("\n\t STACK OPERATIONS USING LINKED LIST");
   printf("\n\t--------------------------------");
   printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

   do {
       
       
       printf("\n Enter the Choice:");
       scanf("%d",&choice);

       switch(choice) {
           case 1: {
              int value;
              printf("Enter value to be Pushed : ");
              scanf("%d",&value);
              push(value);
              break;
           }

           case 2: {

               pop();
               break;
           }

           case 3: {
               printList();
               break;
           }
           case 4: {
               printf("\n\t EXIT POINT ");
               break;
           }
           default : {
               printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
           }


       }
   } while(choice != 4);


    return 0;
}
