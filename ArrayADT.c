#include <stdio.h>
#include <stdlib.h>

struct ArrayADT
{
    int capacity;
    int lastIndex;
    int *ptr;
};
// create ArrayADT structure variable using DMA (in heap memory)
struct ArrayADT * createArrayADT(int cap)
{
    struct ArrayADT *arr;
    arr = (struct ArrayADT *)malloc(sizeof(struct ArrayADT));
    arr->capacity = cap;
    arr->lastIndex = -1;
    arr->ptr = (int *)malloc(cap * sizeof(int));
    return arr;
}
// printing all the elements of array
void display(struct ArrayADT *arr)
{
    int i;
    for (i = 0; i <= arr->lastIndex; i++)
    {
        printf("%d ", arr->ptr[i]);
    }
    printf("\n");
}
// doubleArray
void doubleArray(struct ArrayADT *arr)
{
    int *temp, i;
    temp = (int *)malloc(sizeof(int) * (arr->capacity * 2));
    for (i = 0; i <= arr->lastIndex; i++)
    {
        temp[i] = arr->ptr[i];
    }
    free(arr->ptr);
    arr->ptr = temp;
    arr->capacity = arr->capacity*2;
}
// append
void append(struct ArrayADT *arr, int value)
{
    if (arr->lastIndex == arr->capacity - 1)
    {
        // printf("Overflow\n");
        doubleArray(arr);
        printf("New capacity is: %d\n",arr->capacity);
    }
        arr->lastIndex++;
        arr->ptr[arr->lastIndex] = value;
}
// insert
void insert(struct ArrayADT *arr, int index, int value)
{
    int i;
    if (arr->lastIndex == arr->capacity - 1)
    {
        // printf("Overflow\n");
        doubleArray(arr);
        printf("New capacity is: %d\n",arr->capacity);

    }
    if (index < 0 || index > arr->lastIndex + 1)
    {
        printf("Invalid index\n");
    }
    
    for (i = arr->lastIndex; i >= index; i--)
    {
            arr->ptr[i + 1] = arr->ptr[i];
    }
    arr->ptr[index] = value;
    arr->lastIndex++;
    
}
// halfArray
void halfArray(struct ArrayADT *arr)
{
    int *temp, i;
    temp = (int *)malloc(sizeof(int) * arr->capacity / 2);
    for (i = 0; i <= arr->lastIndex; i++)
    {
        temp[i] = arr->ptr[i];
    }
    free(arr->ptr);
    arr->ptr = temp;
    arr->capacity = arr->capacity/2;
}
// delete ----> to delete a value from array at the given index
void delete (struct ArrayADT *arr, int index)
{
    int i;
    if (index < 0 || index > arr->lastIndex)
    {
        printf("Invalid Index or Underflow\n");
    }
    else
    {
        for (i = index; i < arr->lastIndex; i++)
        {
            arr->ptr[i] = arr->ptr[i + 1];
        }
        arr->lastIndex--;
        //calling halfArray();
        if (arr->lastIndex < (arr->capacity / 2))
        {
            halfArray(arr);
            printf("New capacity is: %d\n",arr->capacity);
        }
    }
}
// replace or edit
void replace(struct ArrayADT *arr, int index, int value)
{
    if (index < 0 || index > arr->lastIndex)
    {
        printf("Invalid Index\n");
    }
    else
    {
        arr->ptr[index] = value;
    }
}
// length or countItem function
int length(struct ArrayADT *arr)
{
    return arr->lastIndex + 1;
}

// get ----->  to get a value at the given index
int getValue(struct ArrayADT *arr, int index)
{
    if (index < 0 || index > arr->lastIndex)
    {
        printf("Invalid Index");
        return (-1);
    }
    return arr->ptr[index];
}

// testing of the above ArrayADT data structure is done in main using switch case
int main()
{
    int choice, cap, index, value;
    printf("1. createArray\n");
    printf("2. append\n");
    printf("3. insert\n");
    printf("4. delete\n");
    printf("5. replace\n");
    printf("6. length\n");
    printf("7. getValue\n");
    printf("8. display\n");
    printf("9. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            //createArray
        case 1:
            printf("Enter the size of array: ");
            scanf("%d", &cap);
            struct ArrayADT *arr;
            arr = createArrayADT(cap);
            break;
            //append
        case 2:
            printf("Enter the value to append: ");
            scanf("%d", &value);
            append(arr, value);
            break;
            //insert
        case 3:
            printf("Enter the index and value at which you want to insert: ");
            scanf("%d%d", &index, &value);
            insert(arr, index, value);
            break;
            //delete
        case 4:
            printf("Enter the index at which you want to delete the item: ");
            scanf("%d", &index);
            delete (arr, index);
            break;
            //replace
        case 5:
            printf("Enter the index and value to replace/edit: ");
            scanf("%d%d", &index, &value);
            replace(arr, index, value);
            break;
            //length or count or number of elemets present in the array
        case 6:
            printf("length=%d\n", length(arr));
            break;
            //getValue
        case 7:
            printf("Enter the index: ");
            scanf("%d", &index);
            getValue(arr, index);
            break;
            //display
        case 8:
            display(arr);
            break;
            //exit
        case 9:
            exit(0);
            //default case
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}