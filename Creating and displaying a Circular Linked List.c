#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=0,*last=0;


int main(){
    struct node *t,*p;
    int i,count=0;

    first = (struct node *)malloc(sizeof(struct node));
    first->data = NULL;
    first->next = NULL;
    last = first;

    do{
        t = (struct node *)malloc(sizeof(struct node));
        if(t==NULL){
            printf("\nHeap is Full");
            break;
        }
        else{
            scanf("%d",&t->data);
            if(first->data==NULL && count==0 && (t->data!=0 || t->data==0))
                first=last=t;
            else{
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        count++;
        scanf("%d",&i);
    }while(i);


    last->next = first; // This line will basically make the linked list circular
    p = first;
    count=0;

    // Displaying the Circular Linked List
    while(p!=first || count!=1){
        count=1;
        printf("\n%d",p->data);
        p = p->next;
    }
}
