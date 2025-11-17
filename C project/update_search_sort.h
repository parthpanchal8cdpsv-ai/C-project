#ifndef UPDATE_SEARCH_SORT_H
#define UPDATE_SEARCH_SORT_H
#include "insert_delete_view.h"
void update_item(struct item *head,char name[],char field[],int field_val);

void search_item_by_name(struct item *head,char *name);

void sort_by_field(struct item *head,char sort_field[]);

void check_stock(struct item*head);

int check_item(struct item*head,char name[20]);


#endif