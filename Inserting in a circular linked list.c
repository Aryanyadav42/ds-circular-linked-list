#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=0,*last=0;

void Inserting(int *data,int *index){
    struct node *p,*q,*t;
    int i;

    t = (struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("\nHeap is Full");

    else{
        t->data = *data;

        int count=0;
        p=first;
        while(p!=last){
            count++;
            p = p->next;
        }




        if(*index==0){
            t->next = first;
            first = t;
            last->next = first;
        }

        else if(*index>count){
            last->next = t;
            last = t;
            last->next = first;
        }

        else if(*index>0 && *index<=count){
            q = NULL;
            p = first;
            for(i=0;i<*index;i++){
                q = p;
                p = p->next;
            }
            t->next = q->next;
            q->next = t;
        }
    }
}

int main(){
    void Inserting();
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

    int data,index;
    printf("\nEnter the data you want to insert : ");
    scanf("%d",&data);

    printf("\nEnter the index you want to insert the data : ");
    scanf("%d",&index);

    Inserting(&data,&index);


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
