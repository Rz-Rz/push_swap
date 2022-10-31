#include "push_swap.h"

// Function: put_target_pos
// Description: Put the target_pos of each node in stack_b. The target_pos correspond to the position it should hold in stack_a. To find the target_pos we seek in stack_a the index the closest but always superior to the index in stack_b. If the element in stack_b has an index greater than all elements of stack_a, we use as target_pos the smallest index in stack_a. 
// Input: node *stack_b - the linked list to put the target_pos in.
//        node *stack_a - the linked list to use to evaluate the target_pos.
// Output: void
void	put_target_pos(node *stack_b, node *stack_a)
{
	node	*tmp;
	int		i;
	int		j;
	int		index;
	int		target_pos;

	tmp = stack_b;
	while (tmp)
	{
		i = 0;
		j = 0;
		index = tmp->index;
		while (stack_a)
		{
			if (stack_a->index > index)
			{
				target_pos = i;
				break ;
			}
			stack_a = stack_a->next;
			i++;
		}
		if (stack_a == NULL)
			target_pos = j;
		tmp->target_pos = target_pos;
		tmp = tmp->next;
	}
}
