/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/11 22:11:09 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: sort_2
// Description: Sort the stack_a with 2 elements
// Input: node **stack_a - the stack to sort
// Output: void
void	sort_2(node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 1);
}

// Function: sort_3
// Description: Sort the stack_a with 3 elements using the index of the nodes.
// Input: node **stack_a - the stack to sort
// Output: void
void	sort_3(node **stack_a)
{
	put_index(*stack_a, NULL);
	while (!is_ordered(*stack_a))
	{
		if ((*stack_a)->index > (*stack_a)->next->index &&
			(*stack_a)->index > (*stack_a)->next->next->index)
			ra(stack_a, 1);
		else if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

// Function: sort
// Description: Sort the stack_a with n>3 elements using the index of the nodes.
// To decide of the most efficient action, we compare the numbers of action that
// will cost to put each element at the top of the pile. Then we choose the
// cheapest sequence.
//  First we pb all the elements of stack_a except 3 elements. Then we sort the
//  3 elements with sort_3. Then we pa the elements of stack_b in the right
//  order. As long as there are elements in stack_b we loop. First we find the
//  actual position of all in stack_a and stack_b. Then we compute the target
//  position (i.e. the index) of stack_a where each elements of stack_b should
//  be. Then we numbers of action to put each element of stack_b to its target
//  position in stack_a and we choose the cheapest option. Then we do the set of
//  action needed to move the elements from stack_b to stack_a. Input: node
//  **stack_a - the stack to sort to. node **stack_b - the stack to sort from.
//  Output: void
void	sort(node **stack_a, node **stack_b)
{
	node	*to_sort;

	push_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		put_pos(*stack_a, *stack_b);
		put_index(*stack_a, *stack_b);
		put_target_pos(*stack_a, *stack_b);
		put_costs(*stack_a, *stack_b);
		to_sort = find_cheapest_action(*stack_b);
		do_actions(stack_a, stack_b, to_sort);
	}
	rotate_until_sorted(stack_a);
}

// Function: push_to_b
// Description: Push all the elements of stack_a to stack_b except 3 elements.
// Then we sort the 3 elements with sort_3. Input: node **stack_a - the stack to
// push from.  node **stack_b - the stack to push to. Output: void
void	push_to_b(node **stack_a, node **stack_b)
{
	int	i;
	int	size;

	size = lst_size(*stack_a);
	put_index(*stack_a, *stack_b);
	median_sorter(stack_a, stack_b, size / 2, size);
	i = 0;
	size = lst_size(*stack_a);
	while (i < size - 3)
	{
		pb(stack_a, stack_b, 1);
		i++;
	}
	sort_3(stack_a);
	put_target_pos(*stack_a, *stack_b);
}

// Function: put_pos
// Description: Put the position of each node in the linked list, starting from
// 0 to lst_size. Input: node *stack_a - the linked list to put the position in.
//        node *stack_b - the linked list to put the position in.
// Output: void
void	put_pos(node *stack_a, node *stack_b)
{
	int		i;
	node	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = stack_b;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
