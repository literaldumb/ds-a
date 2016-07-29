#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int value;
    struct node *next;
};

void push(struct node **head, struct node **tail, int val)
{
    struct node *temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->value = val;
    temp->next = NULL;
    
    if(*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}

void print(struct node *list)
{
    cout << "Printing...\n";
    
    while( list != NULL)
    {
        cout << list->value << ",";
        list = list->next;
    }
}

void split(struct node *list, struct node **list1, struct node **list2)
{
    if(list == NULL)
        return;
        
    struct node *slow=NULL;
    struct node *fast=NULL;
    
    fast=list;
    slow=list;
    
    while(fast->next != NULL)
    {
        if(slow->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast->next != NULL)
        {
            fast = fast->next;
        }
    }
}

void merge()
{
    
}

void mergesort(struct node **list)
{
    struct node *list1=NULL;
    struct node *list2=NULL;
    
    split(*list,&list1,&list2);
    
    mergesort(&list1);
    mergesort(&list2);
    
    *list = merge(&list1,&list2);
}

int main() {
	// your code goes here
	struct node *list=NULL, *tail=NULL;
	push(&list,&tail,4);
	push(&list,&tail,2);
	push(&list,&tail,5);
	push(&list,&tail,3);
	push(&list,&tail,9);
	push(&list,&tail,8);
	push(&list,&tail,6);
	
	//sort
	mergesort(&list);
	
	//print
	print(list);
	return 0;
}
