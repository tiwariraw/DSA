// Stack using Array
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int capacity;
    int top;
    int *ptr;
};

struct Stack *createStack(int cap)
{
    struct Stack *stk;
    stk = (struct Stack *)malloc(sizeof(struct Stack));
    stk->capacity = cap;
    stk->top = -1;
    stk->ptr = (int *)malloc(cap * sizeof(int));
    return stk;
}

void push(struct Stack *stk, int data)
{
    if (stk->top == stk->capacity - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stk->top++;
        stk->ptr[stk->top] = data;
    }
}

void pop(struct Stack *stk)
{
    int data;
    if (stk->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        data = stk->ptr[stk->top];
        stk->top--;
        printf("popped value is: %d\n", data);
        
    }
}

void peek(struct Stack *stk)
{
   if(stk->top == -1){
    printf("Stack is empty\n");
   }else{
    printf("Element at top is: %d\n", stk->ptr[stk->top]);
   }
}

int main()
{
    struct Stack *stk;
    int choice, data, cap;
    while (1)
    {
        printf("1. create stack\n");
        printf("2. push\n");
        printf("3. pop\n");
        printf("4. peek\n");
        printf("5. exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the capacity: ");
            scanf("%d", &cap);
            stk = createStack(cap);
            break;

        case 2:
            printf("Enter an element to push\n");
            scanf("%d", &data);
            push(stk, data);
            break;

        case 3:
            pop(stk);
            break;

        case 4:
            peek(stk);
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