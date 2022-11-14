#include "push_swap.h"

//Function: lst_free
//Description: free the list
//Input: t_node* head - the head of the list
//Output: none
void	lst_free(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

//Function: lst_size
//Description: return the size of the list
//Input: t_node* head - the head of the list
//Output: int - the size of the list
int	lst_size(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

// Function lst_search_target_pos
// Description: Search the t_node in the list with the target_pos passed as parameter.
// Input: t_node *head - the head of the list to search in.
//       int target_pos - the target_pos to search for.
// Output: t_node * - the t_node with the target_pos passed as parameter.
t_node	*lst_search_target_pos(t_node *head, int target_pos)
{
	while (head)
	{
		if (head->pos == target_pos)
			return (head);
		head = head->next;
	}
	return (NULL);
}
