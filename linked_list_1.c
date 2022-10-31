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

//Function: lst_size
//Description: return the size of the list
//Input: node* head - the head of the list
//Output: int - the size of the list
int lst_size(node* head)
{
    int i = 0;
    while (head != NULL)
    {
	head = head->next;
	i++;
    }
    return (i);
}
