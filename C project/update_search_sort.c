#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "update_search_sort.h"

 void update_item(struct item *head,char name[],char field[],int field_val){
    struct item *temp=head;
    while(temp!=NULL){
        if(_stricmp(temp->name,name)==0){
            if(_stricmp(field,"quantity")==0){
                temp->quantity=field_val;
                return;
            }
            if(_stricmp(field,"price")==0){
                temp->price=field_val;
                return;
            }


        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("ITEM NOT FOUND ! \n");
    }
    
}

void search_item_by_name(struct item *head,char *name){
    FILE *fp=fopen("search_result.txt","w");
    fprintf(fp,"--------SEARCH RESULT--------\n");
    if(!fp){
        printf("Error\n");
    }
    

    struct item *temp=head;
    while(temp!=NULL){
        if(strcmp(name,temp->name)==0){
            fprintf(fp,"\nID - %d\n",temp->id);
            fprintf(fp,"Name - %s\n",temp->name);
            fprintf(fp,"Quantity - %d\n",temp->quantity);
            fprintf(fp,"Price - %d\n",temp->price);
            fclose(fp);
            return;
        }
        temp=temp->next;

    }
    fprintf(fp,"\nITEM NOT FOUND !\n");
    fclose(fp);
    
}

void sort_by_field(struct item *head,char sort_field[]){
    struct item *temp=head;
    while(temp!=NULL){
        struct item *temp2=temp->next;
        while(temp2!=NULL){
            if((strcmp("name",sort_field)==0 && strcmp(temp->name,temp2->name)>0) || (strcmp("price",sort_field)==0 && temp->price>temp2->price)||(strcmp("quantity",sort_field)==0 && temp->quantity>temp2->quantity)){
                char *x=temp->name;
                temp->name=temp2->name;
                temp2->name=x;

                int y=temp->price;
                temp->price=temp2->price;
                temp2->price=y;

                int z=temp->quantity;
                temp->quantity=temp2->quantity;
                temp2->quantity=z;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
}

void check_stock(struct item *head){
    FILE *fp=fopen("stock_report.txt","w");
    if(!fp){
        printf("Error\n");
        return;
    }
    fprintf(fp,"ITEMS TO BE RESTOCKED\n");
    fprintf(fp,"--------------------------------\n");
    struct item *temp=head;
    int cntr1=0;

    while(temp!=NULL){
        if(temp->quantity<10){
            cntr1=1;
        }
        temp=temp->next;
    }
    if(cntr1==0){
        fprintf(fp,"[ALL ITEMS IN STOCK]\n");
        fclose(fp);
        return;
    }


    fprintf(fp,"ID                    NAME\n");
  
    

    struct item *temp2=head;
    while(temp2!=NULL){
        if(temp2->quantity<10){
            fprintf(fp,"%d               %s\n",temp2->id,temp2->name);
          
        }
        temp2=temp2->next;
    }
    fclose(fp);
    

 
}

int check_item(struct item *head,char name[20]){
    struct item *temp=head;
    while(temp!=NULL){
        if(_stricmp(temp->name,name)==0){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}