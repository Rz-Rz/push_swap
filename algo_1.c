#include "push_swap.h"

// Function: find_target_pos
// Description: find the target position the elements of stack_a and stack_b in the stack_a and put it in index
// Input: node **stack_a, node **stack_b
// Output: void
void	find_target_pos(node **stack_a, node **stack_b)
{
	int		i;
	int		j;
	int		k;
	int		*index;
	node	*tmp;

	i = 0;
	j = 0;
	k = 0;
	index = nodeval_to_int(*stack_a, *stack_b);
	quick_sort(index, 0, lst_size(*stack_a) + lst_size(*stack_b) - 1);
	tmp = *stack_a;
	while (j < i)
	{
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->value == index[j])
				tmp->index = k;
			tmp = tmp->next;
		}
		tmp = *stack_b;
		while (tmp)
		{
			if (tmp->value == index[j])
				tmp->index = k;
			tmp = tmp->next;
		}
		j++;
		k++;
	}
	free(index);
}


