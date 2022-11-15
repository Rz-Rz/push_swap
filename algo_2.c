/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:19:34 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/15 15:20:34 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: compute_cost
// Description: Compute the cost to put the passed t_node to the top of stack_x.
// Input: t_node *t_node - the linked list to compute the cost in.
// Output: the actual cost to put the passed t_node to the top of stack_b.
int	compute_cost(t_node *t_node, int size)
{
	int	cost;

	cost = 0;
	if (t_node->pos <= size / 2)
		cost = t_node->pos;
	else
	{
		cost = size - t_node->pos;
		cost *= -1;
	}
	return (cost);
}

// Function: compute_cost_a
// Description: Compute the cost to put the / 
// corresponding t_node of target_pos to
// the top of stack_a. Input: t_node / 
// *t_node_b - the linked list to compute the cost
// in.
//       t_node *stack_a - the linked list to compute the cost in.
//       int size - the size of stack_a.
// Output: the actual cost to put the passed t_node to the top of stack_a.
int	compute_cost_a(t_node *t_node_b, t_node *stack_a, int size)
{
	t_node	*tmp_a;
	int		cost;

	tmp_a = lst_search_target_pos(stack_a, t_node_b->target_pos);
	cost = compute_cost(tmp_a, size);
	return (cost);
}

// Function: find_cheapest_action
// Description: Find the cheapest action to do.
// Input : t_node *stack_b - the linked list to compute the cost in.
// Output : t_node * - the t_node with the cheapest action.
t_node	*find_cheapest_action(t_node *stack_b)
{
	t_node	*curr;
	t_node	*cheapest;
	int		min;
	int		res;

	curr = stack_b;
	cheapest = curr;
	min = 500;
	while (curr)
	{
		res = ft_abs(curr->cost_a) + ft_abs(curr->cost_b);
		if (res < min)
		{
			min = res;
			cheapest = curr;
		}
		curr = curr->next;
	}
	return (cheapest);
}

// Function: do_actions
// Description: Do the actions needed to put the t_node in stack_b in the right
// position in stack_a. Input: t_node *stack_b / 
// - the linked list to do the actions
// in.
//       t_node *stack_a - the linked list to do the actions in.
//       t_node *to_sort - the t_node to sort.
// Output: void
void	do_actions(t_node **stack_a, t_node **stack_b, t_node *to_sort)
{
	int	i;

	i = 0;
	r_actions_same_sign(stack_a, stack_b, to_sort);
	if (to_sort->cost_a > 0 && to_sort->cost_b > 0)
	{
	}
	while (i < ft_abs(to_sort->cost_a))
	{
		if (to_sort->cost_a > 0)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		i++;
	}
	i = 0;
	while (i < ft_abs(to_sort->cost_b))
	{
		if (to_sort->cost_b > 0)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
		i++;
	}
	pa(stack_a, stack_b, 1);
}

// Function: rotate_until_sorted
// Description: Rotate the stack until the t_node is sorted.
// Input: t_node *stack_a - the linked list to do the actions in.
// Output: void
void	rotate_until_sorted(t_node **stack_a)
{
	int	min_pos;

	put_pos(*stack_a, NULL);
	min_pos = get_pos_of_smallest_index(*stack_a);
	if (min_pos < lst_size(*stack_a) / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < lst_size(*stack_a))
		{
			rra(stack_a, 1);
			min_pos++;
		}
	}
}
