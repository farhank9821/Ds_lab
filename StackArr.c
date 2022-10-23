#include <stdio.h>
int stack[100], choice, size, top, n, i;
void push(void);
void pop(void);
void display(void);
void peek(void);
int main()
{

    top = -1;
    printf("\n Enter the size of STACK:");
    scanf("%d", &size);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }

        case 5:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 5);
    return 0;
}
void push()
{
    if (top == size - 1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("stack is empty");
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The elements in STACK \n");
        for (i = 0; i <= top; i++)
            printf("\n%d", stack[i]);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("top element is %d", stack[top]);
    }
}
