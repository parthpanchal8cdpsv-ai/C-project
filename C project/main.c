#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "insert_delete_view.h"
#include "update_search_sort.h"

void save_table(const char *filename,struct item *head){
FILE *fp=fopen(filename,"w");
if(!fp){
    printf("Error_404_file_not_found\n",filename);
    return;
}
struct item *temp=head;

fprintf(fp,"%-10s %-15s %-12s %-10s\n", "ID", "Name", "Quantity", "Price");
fprintf(fp,"------------------------------------------------\n");
while(temp!=NULL){
    if(temp->quantity<10){
        fprintf(fp,"%-10d %-15s %-12d %-10d",temp->id,temp->name,temp->quantity,temp->price);
    }
    else{
        fprintf(fp,"%-10d %-15s %-12d %-10d",temp->id,temp->name,temp->quantity,temp->price);
    }
    fprintf(fp,"\n------------------------------------------------\n");
    temp=temp->next;
}
time_t now=time(NULL);
char *timestamp=ctime(&now);
timestamp[strcspn(timestamp,"\n")]=0;
fprintf(fp,"\nLast Modified : %s\n",timestamp);
fclose(fp);
}


int main(){
    
    struct item *i1=malloc(sizeof(struct item));
    struct item *i2=malloc(sizeof(struct item));
    struct item *head=i1;

    i1->id=1;
    i1->name="apple";
    i1->quantity=100;
    i1->price=20;
    i1->next=NULL;

   /*   insertion is  at 1 based index  */
    
    head=insert_item(head,2,2,"banana",120,25); 
    head=insert_item(head,3,3,"orange",135,30);
    head=insert_item(head,4,4,"watermelon",125,40);
    head=insert_item(head,5,5,"mango",110,35);
     

    
    save_table("tablee.txt",head);

    while(1){
        char command[20];
        printf("\nEnter command : ");
        scanf("%s",command);
        printf("\n");

        if(_stricmp(command,"add_item")!=0 && _stricmp(command,"view_items")!=0 && _stricmp(command,"delete_item")!=0 && _stricmp(command,"update_item")!=0 && _stricmp(command,"Search_item")!=0 && _stricmp(command,"sort_items")!=0 && _stricmp(command,"Check_stock")!=0 && _stricmp(command,"Exit")!=0){
            printf("INVALID COMMAND !\n");
        }

        if(_stricmp(command,"add_item")==0){
            char item_name[20];
            printf("Enter item name : ");
            scanf("%s",item_name);
            printf("\n");

            int item_quantity;
            printf("Enter item quantity : ");
            scanf("%d",&item_quantity);
            printf("\n");

            int item_price;
            printf("Enter item price : ");
            scanf("%d",&item_price); 
            printf("\n");
            
            int pos;
            printf("Enter position to add item ( enter -1 to insert at end) : ");
            scanf("%d",&pos);
    
            head=insert_item(head,pos,pos,item_name,item_quantity,item_price);
            save_table("tablee.txt",head);

            
        }


        if(_stricmp(command,"view_items")==0){
            view_items(head);
        }

        if(_stricmp(command,"delete_item")==0){
            char name[20];
            printf("Enter item name : ");
            scanf("%s",name);
            head=delete_item(head,name);
            save_table("tablee.txt",head);


        }

        if(_stricmp(command,"update_item")==0){
            char name[20];
            
            printf("Enter item name : ");
            scanf("%s",name);
            printf("\n");

            if(check_item(head,name)==(0)){
                printf("ITEM NOT FOUND ! \n");
            }
            else{

                char field[20];
                printf("Enter the field you want to change (price/quantity) : ");
                scanf("%s",field);
                printf("\n");

                int field_val;
                printf("Enter the new value of %s : ",field);
                scanf("%d",&field_val);
                

                update_item(head,name,field,field_val);
                save_table("tablee.txt",head);
                check_stock(head);

            }
        }

        if(_stricmp(command,"Search_item")==0){
            char name[20];
            printf("Enter item name : ");
            scanf("%s",name);

            search_item_by_name(head,name);


        }

        if(_stricmp(command,"sort_items")==0){
            char field[20];
            printf("Enter the field by which you want to sort : ");
            scanf("%s",field);
            sort_by_field(head,field);
            save_table("tablee.txt",head);

        }

        if(_stricmp(command,"Check_stock")==0){
            check_stock(head);
        }

        if(_stricmp(command,"Exit")==0){
            break;
        }



    }


  

    return 0;  

}