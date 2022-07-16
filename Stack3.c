// Stack using Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};

struct node *createNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return n;
}

void push(struct node **s, int data)
{
    struct node *n;
    n = createNode();
    if(n != NULL){
    n->item = data;
    n->next = *s;
    *s = n;
    }
}

void peek(struct node *s){
    if(s == NULL){
    printf("Stack is empty\n");
    }
    else{
        printf("Element at top is: %d\n",s->item);
    }
}

void pop(struct node **s)
{
    int data;
    if (*s == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct node *temp;
        temp = *s;
        *s = temp->next;
        data = temp->item;
        free(temp);    
        printf("popped value is: %d\n", data);  
    }
}

void removeStack(struct node **s){
    if(*s == NULL){
        printf("Stack is empty\n");
    }
    while(*s != NULL){
        pop(s);
    }
}

int main()
{
    struct node *stk = NULL;
    int choice, data;
    while (1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. remove the entire stack\n");
        printf("5. exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an element to push\n");
            scanf("%d", &data);
            push(&stk, data);
            break;

        case 2:
            pop(&stk);
            break;

        case 3:
            peek(stk);
            break;

        case 4:
        removeStack(&stk);
        break;

        case 5:
            exit(0);
            break;

        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}