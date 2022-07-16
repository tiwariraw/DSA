#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
void display(struct node *p)
{
    if (p == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (p != NULL)
        {
            printf(" %d ", p->item);
            p = p->next;
        }
        printf("\n");
    }
}
// this function will also handle automatically insertion at begining of the list when the list is empty
void insertAtStart(struct node **s, int data)
{
    // create a node to be inserted
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    // prepare the newly created node with appropriate values
    n->item = data;
    n->next = *s; // assign content of start variable i.e. *s to next(link) of newly created node
    *s = n;
}
void insertAtLast(struct node **s, int data)
{
    // create a node to be inserted
    struct node *n, *p;
    n = (struct node *)malloc(sizeof(struct node));
    // prepare the newly created node with appropriate values
    n->item = data;
    n->next = NULL;
    // adding this new node to the linked list :2 cases
    // 1. if the list is empty
    if (*s == NULL)
    {
        *s = n;
    }
    else
    {
        p = *s;
        // loop to get the address of second last node (which was earlier last node before insertion at last)
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }
}
// search function (it return the address)
struct node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->item == key)
        {
            return p;
        }
        p = p->next;
    }
    return p; // here p will contain NULL which will be returned
}
void insertAfterANode(struct node *s, int data, int key)
{
    struct node *n, *p;
    if (s != NULL)
    {
        n = (struct node *)malloc(sizeof(struct node));
        n->item = data;
        p = search(s, key);
        n->next = p->next;
        p->next = n;
    }
}
void deleteFirst(struct node **s)
{
    if (*s == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        // store the content of start i.e *s in p so as to free the memory of the first node pointed by p
        struct node *p;
        p = *s;
        *s = (*s)->next;
        free(p);
    }
}
// in deleteLastNode, jab ek hi node hoga list me tab start me bhi changes ho sakta hai
void deleteLastNode(struct node **s)
{
    struct node *p1, *p2;
    if (*s == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        p1 = *s;
        p2 = NULL;
        while (p1->next != NULL)
        {
            p2 = p1;
            p1 = p1->next;
        }
        if (p2 == NULL)
        {
            printf("list is having only one node\n");
            *s = NULL;
            free(p1);
        }
        // list is having atleast two nodes
        else
        {
            p2->next = NULL;
            free(p1);
        }
    }
}
void deleteANode(struct node **s, int key)
{
    struct node *p, *r;
    p = search(*s, key);
    if (p == NULL)
    {
        printf("Key not found\n");
    }
    else
    {
        // if the node specified to deleted is the first node
        if (*s == p)
        {
            deleteFirst(s);
        }
        // ye condition hai, jis node ko delete karna hai wo exist bhi karta hai aur pehla node bhi nahi hai (tabhi to iss else me aaye hai)
        // so now we need the address of the node to be deleted
        else
        {
            r = *s;
            while (r->next != p)
            {
                r = r->next;
            }
            r->next = p->next;
            free(p);
        }
    }
}

int main()
{
    struct node *start = NULL;
    int choice, data, key;
    // we assume that the person who will use our data structure will have already created a linked list.
    while (1)
    {
        printf("1. insert at start\n");
        printf("2. insert at last\n");
        printf("3. insert after a node\n");
        printf("4. delete first node\n");
        printf("5. delete last node\n");
        printf("6. delete a specific node\n");
        printf("7. display the elements of the linked list\n");
        printf("8. exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at start: ");
            scanf("%d", &data);
            insertAtStart(&start, data);
            break;

        case 2:
            printf("Enter the data to insert at last: ");
            scanf("%d", &data);
            insertAtLast(&start, data);
            break;

        case 3:
            printf("Enter the data to be inserted and key: ");
            scanf("%d%d", &data, &key);
            insertAfterANode(start, data, key);
            break;

        case 4:
            deleteFirst(&start);
            break;

        case 5:
            deleteLastNode(&start);
            break;

        case 6:
            printf("Enter the key: ");
            scanf("%d", &key);
            deleteANode(&start, key);
            break;

        case 7:
            printf("The list elements are: \n");
            display(start);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Wrong Choice\n");
            break;
        }
    }

    return 0;
}