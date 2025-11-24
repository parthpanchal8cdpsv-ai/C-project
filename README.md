*We have built a simple INVENTORY MANAGEMENT SYSTEM for a store.
*FEATURES- 

          *Stores a list of all items

          *Allows user to add or remove items
          
          *Allows user to change the price/quantity of items
          
          *Allows user to sort the items according to price/quantity
          
          *Allows user to check the stock for item , which returns a table with items not in stock

          *Allows user to search and item by name , which results in a table with the items index number, price and quantity
          

*IMPLEMENTATION & EXPLANATIONS OF FUNCTIONS - 

                                            * The items are stored as a linked list and each node of the list consists of item name , price ,quantity and a pointer to the next node
                                            * (VIEW ITEMS AND SAVE TABLE FUNCTION)The table consisting of all items with their info is made on a separate file using file i/o (fopen and fprintf)
                                            * (INSERT ITEM FUNCTION)To add an item , its basically a problem of adding a node to linked list . To add a node , we just use a loop to find the pointer to the node just before the node where we want a new node to be inserted
                                            
                                            *(UPDATE ITEM FUNCTION) To update an item ,we use a loop to find the pointer to the node of that item and simply update the values according to the given values.
                                            
                                            *(DELETE ITEM FUNCTION)To remove and item , its again a simple problem . We again find the node just before the node to be deleted 
                                            
                                            *(SORT BY FIELD FUNCTION)To sort the items , its very similar to sorting an array . We use a double  nested loop and compare two nodes at a time with price/quantity . We "switch" the nodes (if needed ) by simply switching their contents 
                                            
                                            *(CHECK STOCK FUNCTION)For checking the stock of each item , we use a loop to go through each item and if the quantity is very less , then its added into a table of low stock items.The table of low stock items is made on a different file using file i/o.
                                            
                                            *(SEARCH ITEM BY NAME FUNCTION)Searching an item by name is done through a loop which breaks when it finds the name . A table is made on a separate file showing the search result.

*FUNCTION PARAMETERS-  

                     *VIEW ITEMS FUNCTION - pointer to head node

                     *SAVE TABLE FUNCTION -pointer to filename and head
                     
                     *INSERT ITEM FUNCTION - pointer to head,position to be inserted ; name , quantity and price of new item

                     *UPDATE ITEM FUNCTION- pointer to head, name of item , field to be updated(price/quantity), new value of field
                     
                     *DELETE ITEM - pointer to head,name of item
                     
                     *SORT BY FIELD FUNCTION -pointer to head, field by which to sort(price/quantity)
                     
                     *CHECK STOCK FUNCTION - pointer to head
                     
                     *SEARCH ITEM BY NAME FUNCTION - pointer to head, name of item

                     
                
                
                
