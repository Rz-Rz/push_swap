#include "push_swap.h"

// Function: put_target_pos
// Description: Put the target_pos of each node in stack_b. The target_pos correspond to the position it should hold in stack_a. To find the target_pos we seek in stack_a the index the closest but always superior to the index in stack_b. If the element in stack_b has an index greater than all elements of stack_a, we use as target_pos the smallest index in stack_a. 
// Input: node *stack_b - the linked list to put the target_pos in.
//        node *stack_a - the linked list to use to evaluate the target_pos.
// Output: void
void	put_target_pos(node *stack_b, node *stack_a)
{
	node *tmp_b;
	node *tmp_a;
	int res;
	int min;

	min = 500;
	tmp_b = stack_b;
	while (tmp_b)
	{
		tmp_a = stack_a;
		min = 500;
		if (!is_superior(tmp_b, stack_a))
		{
			while (tmp_a)
			{
				res = ft_abs(tmp_b->index - tmp_a->index);
				if (res < min && tmp_b->index < tmp_a->index)
				{
					min = res;
					tmp_b->target_pos = tmp_a->pos;
				}
				tmp_a = tmp_a->next;
			}
		}
		else 
			tmp_b->target_pos = get_pos_of_smallest_index(stack_a);
		tmp_b = tmp_b->next;
	}
}

// Function: is_superior
// Description: Check if the index of the node in stack_b is superior to all the indexes in stack_a. If it is, we return 1, else we return 0.
// Input: node *stack_b - the linked list to check the index in.
//       node *stack_a - the linked list to check the index in.
//       int res - the result of the comparison.
// Output: int - 1 if the index of the node in stack_b is superior to all the indexes in stack_a, else 0.
int	is_superior(node *stack_b, node *stack_a)
{
	int res;

	res = 0;
	while (stack_a)
	{
		if (stack_b->index > stack_a->index)
			res = 1;
		else
			return (0);
		stack_a = stack_a->next;
	}
	return (res);
}

// Function get_pos_of_smallest_index
// Description: Get the position of the smallest index in stack_a.
// Input: node *stack_a - the linked list to get the position of the smallest index in.
// Output: int - the position of the smallest index in stack_a.
int	get_pos_of_smallest_index(node *stack_a)
{
	int min;
	int pos;

	min = 500;
	pos = 0;
	while (stack_a)
	{
		if (stack_a->index < min)
		{
			min = stack_a->index;
			pos = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
	return (pos);
}
