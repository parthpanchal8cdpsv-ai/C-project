#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insert_delete_view.h"


struct item *insert_item(struct item*head,int pos,int id,char *name,int quantity,int price){
    
    if(pos==-1){
        struct item *temp=head;
        struct item *new=malloc(sizeof(struct item));
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
        new->name=name;
        new->quantity=quantity;
        new->price=price;
        struct item *id_set=head;
        int i=1;
        while(id_set!=NULL){
            id_set->id=i;
            id_set=id_set->next;
            i++;
        }
        return head;
        
    }
    /* pos is 1 index based */
    else{
        pos=pos-1;
    }
   
    struct item *check=head;
    while(check!=NULL){
        if(_stricmp(check->name,name)==0){
            printf("ITEM ALREADY IN INVENTORY ! \n");
            return head;
        }
        check=check->next;
    }

    if(pos==0){
        struct item *new=malloc(sizeof(struct item));
        new->next=head;
        new->id=pos;
        new->name = malloc(strlen(name) + 1);
        strcpy(new->name, name);
        new->quantity=quantity;
        new->price=price;
       
        int id_cnt=1;
        struct item *temp=new;
        while(temp!=NULL){
            temp->id=id_cnt;
            id_cnt++;
            temp=temp->next;
        }
        return new;

    }
    
    struct item *new=malloc(sizeof(struct item));
    struct item *temp=head;
    int i=0;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    new->next=temp->next;
    temp->next=new;
    new->name=name;
    new->quantity=quantity;
    new->price=price;

    int id2=1;
    struct item *id_set=head;
    while(id_set!=NULL){
        id_set->id=id2;
        id2++;
        id_set=id_set->next;

    }
    return head;
   

}


struct item *delete_item(struct item *head,char name[]){
    
    if(_stricmp(head->name,name)==0){
        head=head->next;
        int id=1;
        struct item *temp=head;
        while(temp!=NULL){
            temp->id=id;
            id++;
            temp=temp->next;
        }
        return head;
    }
    struct item *temp=head;
    while(temp->next!=NULL){
        if(_stricmp(temp->next->name,name)==0){
            temp->next=temp->next->next;
            int id=1;
            struct item *id_check=head;
            while(id_check!=NULL){
                id_check->id=id;
                id++;
                id_check=id_check->next;
            }
            return head;
        }
        temp=temp->next;
    }
    
    if(temp->next==NULL){
        printf("ITEM NOT FOUND !\n");
        return head;
    }

}


void view_items(struct item *head){
    printf("%-10s %-15s %-12s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
    while(head!=NULL){
        printf("%-10d %-15s %-12d %-10d",head->id,head->name,head->quantity,head->price);
        printf("\n------------------------------------------------\n");
        head=head->next;
    }


}
