#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * getnode(int val){ //create a node.
    struct node *var = (struct node *)malloc(sizeof(struct node));
    var->data = val;
    var->next = NULL;
    return var;
}

void display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node * addAtFront(struct node *head,int val){ //need atleast one element.
    struct node *var = getnode(val);
    var->next = head;
    head = var;
    return head;
}

struct node * deleteFromFront(struct node *head){
    struct node *temp = head;
    head = temp->next;
    free(temp);
    return head;
}

struct node * addAtEnd(struct node *head,int val){ //need atleast one element.
    struct node *var = getnode(val);
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = var;
    return head;
}

struct node * deleteFromEnd(struct node *head){
    struct node *var = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        while((temp->next)->next != NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }    
    return head;
}

struct node * addAtPos(struct node *head,int index,int val){ //for 0th index use addAtFront.
    int i;
    struct node *var = getnode(val);
    struct node *temp = head;
    for(i=1;i<index;i++){
        temp = temp->next;
    }
    struct node *nxtNode = temp->next;
    temp->next = var;
    var->next = nxtNode;
    return head;
}

struct node * deleteAtPos(struct node *head,int index){ //for 0th index use deleteFromFront.
    int i;
    struct node *temp = head;
    for(i=1;i<index;i++){
        temp = temp->next;
    }
    struct node *targetNode = temp->next;
    temp->next = targetNode->next;
    free(targetNode);
    return head;
}

int main(int argc, char const *argv[])
{
    struct node *head;
    struct node *one = getnode(2);
    head = one;
    head = addAtEnd(head,4);
    head = addAtEnd(head,6);
    head = addAtEnd(head,8);
    head = addAtPos(head,2,99);
    head = addAtPos(head,5,89);
    head = addAtPos(head,1,9);
    head = deleteAtPos(head,4);
    head = deleteAtPos(head,5);
    head = deleteAtPos(head,1);
    head = deleteFromFront(head);
    display(head);
    //printf("%d %d %d",head->data,(head->next)->data,one->data);
    return 0;
}
