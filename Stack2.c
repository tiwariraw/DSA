// Stack using dynamic Array
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
// doubleArray
void doubleArray(struct Stack *stk)
{
    int *temp, i;
    temp = (int *)malloc(sizeof(int) * (stk->capacity * 2));
    for (i = 0; i <= stk->top; i++)
    {
        temp[i] = stk->ptr[i];
    }
    free(stk->ptr);
    stk->ptr = temp;
    stk->capacity = stk->capacity * 2;
}

void push(struct Stack *stk, int data)
{
    if (stk->top == stk->capacity - 1)
    {
        // printf("Stack Overflow\n");
        doubleArray(stk);
        printf("Capacity Doubled\n");
        printf("New capacity is: %d\n", stk->capacity);
    }
    stk->top++;
    stk->ptr[stk->top] = data;
}

// halfArray
void halfArray(struct Stack *stk)
{
    int *temp, i;
    temp = (int *)malloc(sizeof(int) * stk->capacity / 2);
    for (i = 0; i <= stk->top; i++)
    {
        temp[i] = stk->ptr[i];
    }
    free(stk->ptr);
    stk->ptr = temp;
    stk->capacity = stk->capacity/2;
}

void pop(struct Stack *stk)
{
    int data;
    if (stk->top < stk->capacity/2)
    {
        // printf("Stack Underflow\n");
        halfArray(stk);
         printf("Capacity Reduced by \"HALF\"\n");
        printf("New capacity is: %d\n", stk->capacity);
    }
    data = stk->ptr[stk->top];
    stk->top--;
    printf("popped value is: %d\n", data);
}

void peek(struct Stack *stk)
{
    if (stk->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
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