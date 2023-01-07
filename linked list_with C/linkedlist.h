#include"stdio.h"
#include"stdlib.h"
typedef unsigned short int  uint16;
typedef unsigned char       uint8;

typedef struct node{
	uint16 Data;
	struct node* Next;
}node;

node* Creat_Node(uint16);
//make head point to first node in list
void Append_Node(node**H_ptr ,node*new);
//print all list
void print_list(node* head);
//delete all list
void delete_list(node ** head);
//delete first node
uint16 pop_head(node **head);
//delete the last node
uint16 remove_last(node * head,node **H_ptr);
//add node at any index (place)
void insert_by_index(node* head,node **H_ptr,uint16 data ,uint8 n);
//remove node at any index (place)
uint16 remove_by_index(node ** H_ptr, uint8 n);
//search for data and return index
uint16 search_element (node* head,uint16 item);		
