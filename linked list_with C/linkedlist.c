/*
 * 	linkedlist.c
 *
 *  Created on: DEC 24, 2022
 *      Author: kholoud khaled
 */

#include "linkedlist.h"

node* Creat_Node(uint16 data){
	// great pointer to struct
	node* temp;
	//allocate size of node in heap
	temp=(node*)malloc(1* sizeof(node));
	if (temp!=NULL){//find memory in heap
		temp->Data =data;
		temp->Next =NULL;
	}
	return (temp);
}

//add node at end of list (last node)
void Append_Node(node**H_ptr ,node* new){
	//copy from haed pointer to loop
	node* current =* H_ptr;
	//head point to this node
	if (* H_ptr==NULL){
		* H_ptr =new;
	}
	else{
		//loop to every node
		//append where pinter of next countain null last node
		while (current->Next!=NULL){
			current =current->Next;
		}
		current->Next=new;
	}	
}

//print all list
void print_list(node * head){
	node* current;
	current =head;
	if (current ==NULL)
		printf("the linked list is empty\n");
	else{
		while(current !=NULL)
		{
			printf("%d\n",current->Data);
			current =current->Next;
		}

	  }
}

//delete all list
void delete_list(node ** head){
	node *temp;
	while( *head != NULL)
	{
		temp = *head;
		*head = (*head) -> Next;
		free ( temp );
	}
}

//delete first node
uint16 pop_head(node **head){
     if (*head != '\0')
    {
        uint16 retval;
        node * next_node = '\0';
        next_node = (*head)->Next;
        retval = (*head)->Data;
        free(*head);
        *head = next_node;
        return retval;
    }
}

//delete the last node
uint16 remove_last(node * head,node **H_ptr){
    if (*H_ptr != '\0')
    {
        uint16 retval = 0;
		//if there is only one item in the list, remove it 
        if (head->Next == '\0')
        {
           retval=pop_head(H_ptr);
        }
        else
        {
        while (head->Next->Next != '\0')
        {
            head = head->Next;
        }
        retval = head->Next->Data;
        free(head->Next);
        head->Next = '\0';
        }
         return retval;
    }
}


//add node at any index (place)
void insert_by_index(node* head,node** H_ptr,uint16 data ,uint8 n){
	node* temp;
	node* current_node;
	current_node =head;
	uint8 counter;
	if (n<0)
		printf("the index must be positive number which greater than or equal zero\n");
	else{
		//list have no node
		if (head==NULL){
			current_node =Creat_Node(data);
	        Append_Node(H_ptr ,current_node);
		}
		// loop  for point to the node before i insert in
		for(counter=0;counter<n-1;counter++)
        {
            current_node=current_node->Next;
        }
		//allocat node
        temp=(node*)malloc(sizeof(node));
		//put data in data of node
        temp->Data=data;
		//put pointer next of new node
        temp->Next=current_node->Next;
        current_node->Next=temp;

	}
}

//remove node at any index (place)
uint16 remove_by_index(node ** H_ptr, uint8 n){
	node* current = *H_ptr;
    node* temp_node = '\0';
	uint8 i;
	uint16 retval;
	if(n<0)
    {
        printf("the index must be positive number which greater than or equal zero\n");
    }
	else if (n == 0)
    { //if the user inputs 0 so he want to remove the head
        retval=pop_head(H_ptr);
    }
	else if(*H_ptr=='\0')
    {
        printf("the linked list is empty \n");
    }
	else{
		// loop  for point to the node before i insert in
        for (i = 0; i < n-1; i++)
        {
            if (current->Next == '\0')
            {
                return remove_last(*H_ptr,H_ptr);
            }
            current = current->Next;
        }

		temp_node = current->Next;
		retval = temp_node->Data;
		current->Next = temp_node->Next;
		free(temp_node);
    }
    return retval;
}

//search for data and return index
uint16 search_element (node* head,uint16 item){
  node*current=head;
  uint16 index=0;
  // traverse till then end of the linked list
    while (current != NULL)
    {
        if (current->Data == item){
            return index;
        }
        current = current->Next;
        index++;
	}
	printf(":ze");
   return  (2);
}