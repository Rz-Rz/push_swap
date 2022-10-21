#include "push_swap.h" 

// Function: is_ordered
// Description: Checks if the stack is in correct order. 
// Return: 1 if ordered, 0 if not.
// Parameters: node *stack
int is_ordered(node *stack)
{
    node *tmp;

    tmp = stack;
    while (tmp->next)
    {
	if (tmp->value > tmp->next->value)
	    return (1);
	tmp = tmp->next;
    }
    return (0);
}

// Function: is_duplicate
// Description: Checks if the stack contains duplicates.
// Return: 1 if duplicate, 0 if not.
// Parameters: node *stack
int is_duplicate(node *stack)
{
    node *tmp;
    node *tmp2;

    tmp = stack;
    while (tmp->next)
    {
	tmp2 = tmp->next;
	while (tmp2)
	{
	    if (tmp->value == tmp2->value)
		return (1);
	    tmp2 = tmp2->next;
	}
	tmp = tmp->next;
    }
    return (0);
}

