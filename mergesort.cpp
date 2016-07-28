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
	
	print(list);
	return 0;
}
