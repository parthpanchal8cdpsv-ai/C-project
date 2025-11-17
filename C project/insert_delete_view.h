#ifndef INSERT_DELETE_VIEW_H
#define INSERT_DELETE_VIEW_H

struct item{
    
    int id;
    char *name;
    int quantity;
    int price;
    struct item *next;
};

struct item *insert_item(struct item*head,int pos,int id,char *name,int quantity,int price);

struct item *delete_item(struct item *head,char name[]);

void view_items(struct item *head);



#endif