#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "insert_delete_view.h"
#include "update_search_sort.h"

struct item* load_table(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("No previous table found. Starting fresh.\n");
        return NULL;
    }

    struct item *head = NULL;
    struct item *tail = NULL;

    char line[200];

    // Skip the two header lines
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    int id, quantity, price;
    char name[50];

    while (fgets(line, sizeof(line), fp)) {

        // Skip dashed lines
        if (strstr(line, "-----") != NULL)
            continue;

        // Stop before timestamp line
        if (strstr(line, "Last Modified") != NULL)
            break;

        // Try to parse the line
        if (sscanf(line, "%d %s %d %d", &id, name, &quantity, &price) == 4) {

            struct item *new = malloc(sizeof(struct item));
            new->id = id;

            new->name = malloc(strlen(name) + 1);
            strcpy(new->name, name);

            new->quantity = quantity;
            new->price = price;
            new->next = NULL;

            if (!head)
                head = tail = new;
            else {
                tail->next = new;
                tail = new;
            }
        }
    }

    fclose(fp);
    return head;
}



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
    struct item *head=load_table("tablee.txt");
    
   /*   insertion is  at 1 based index  */
    
   
    
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
            save_table("tablee.txt",head);
            break;
        }



    }


  

    return 0;  

}
