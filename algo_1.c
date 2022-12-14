/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:29:24 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/15 15:22:25 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Function: put_target_pos
// Description: Put the target_pos of each t_node in stack_b. / 
// The target_pos correspond to the position it / 
// should hold in stack_a. To find the target_pos we seek / 
// in stack_a the index the closest but always superior / 
// to the index in stack_b. If the element in stack_b / 
// has an index greater than all elements of stack_a,/ 
// we use as target_pos the smallest index in stack_a.
// Input: t_node *stack_b - the linked list to put the target_pos in.
//        t_node *stack_a - the linked list to use to evaluate the target_pos.
// Output: void
void	put_target_pos(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	tmp_b = stack_b;
	tmp_a = stack_a;
	put_target_bis(tmp_b, stack_a, tmp_a);
}

// Function: put_target_pos_bis
// Description: Put the target_pos of each t_node in stack_b./ 
// The target_pos correspond to the position it should hold /
// in stack_a. To find the target_pos we seek in stack_a the /
// index the closest but always superior to the index in  /
// stack_b. If the element in stack_b has an index greater / 
// than all elements of stack_a,/ 
// we use as target_pos the smallest index in stack_a.
// Input: t_node *stack_b - the linked list to put the target_pos in.
//       t_node *stack_a - the linked list to use to evaluate the target_pos.
void	put_target_bis(t_node *tmp_b, t_node *stack_a, t_node *tmp_a)
{
	int	res;
	int	min;

	tmp_a = stack_a;
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
// Description: Check if the index of the t_node in stack_b is superior/
// to all the indexes in stack_a./
// If it is, we return 1, else we return 0.
// Input: t_node *stack_b - the linked list to check the index in.
//       t_node *stack_a - the linked list to check the index in.
//       int res - the result of the comparison.
// Output: int / 
// - 1 if the index of the t_node in stack_b / 
// is superior to all the indexes in stack_a,
// else 0.
int	is_superior(t_node *stack_b, t_node *stack_a)
{
	int	res;

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
// Input: t_node *stack_a / 
// - the linked list to get the / 
// position of the smallest index in.
// Output: int - the position of the smallest index in stack_a.
int	get_pos_of_smallest_index(t_node *stack_a)
{
	int	min;
	int	pos;

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

// Function: find_nb_action
// Description: Find the number of actions needed to put the/
// t_node in stack_b in the right /
// position in stack_a. We use the target_pos of /
// the t_node in stack_b to find the number of actions needed. /
// We compute the cost for stack_b in cost_b, / 
// and cost for stack_a in cost_a.
// Input: t_node *stack_b / 
// - the linked list to find the number of actions needed in.
// t_node *stack_a / 
// - the linked list to find the number of actions needed in.
// Output: void
void	put_costs(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = stack_b;
	size_a = lst_size(stack_a);
	size_b = lst_size(stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = compute_cost(tmp_b, size_b);
		tmp_b->cost_a = compute_cost_a(tmp_b, stack_a, size_a);
		tmp_b = tmp_b->next;
	}
}
