#include "push_swap.h"


//Function: lst_free
//Description: free the list
//Input: node* head - the head of the list
//Output: none
void lst_free(node* head)
{
    node* temp = head;
    while (head != NULL)
    {
	temp = head;
	head = head->next;
	free(temp);
    }
}
