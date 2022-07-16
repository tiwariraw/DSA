//Singly Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node *next;
};

void insertAtStart(struct node **s, int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));// creating a new node dynamically
    n->item=data;
    n->next=*s;
    *s=n;
    // no need to explicitlly check if the list is empty or not
}

void insertAtLast(struct node **s, int data){
    struct node *n,*p;
    n=(struct node *)malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    //if the list is empty
    if(*s==NULL){
        *s=n; //start me naye node ka address rakh dijiye
    }
    else //if the list is not empty
    { 
    p=*s;// p will also point to the first node of the list
    while(p->next!=NULL)
        p = p->next;
    p->next=n;
    }
}
//search function
struct node * searchANode(struct node *start, int key){
    while(start!=NULL){
        if(start->item==key)
        return start;
        start=start->next;
    }
    return start; //here, NULL will be returned as the while loop will only terminate when start==NULL
}

void insertAfterANode(struct node *t, int data){
    struct node *n;  
    if(t){                      //if(t!=NULL)
    n=(struct node *)malloc(sizeof(struct node));
    n->item = data;
    n->next = t->next;
    t->next = n->next;
    } 
}

int main(){
    struct node *start=NULL;  
    //we are passing the address of pointer variable start so as to make changes in start variable
    insertAtStart(&start,20);
    // insertAtLast(&start,30);
    
    
    return 0;
}