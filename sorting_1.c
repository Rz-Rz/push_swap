/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:52:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/17 19:58:17 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: put_index_bis
// Description: Put the index, the place the number should have,
//	in the linked list.
// Input: t_node *stack_a - the linked list
//       t_node *stack_b - the linked list
// Output: void
void	put_index_bis(t_node *stack_a, t_node *stack_b, int ac, int *arr)
{
	t_node	*curr;
	int		j;

	j = 0;
	while (j < ac)
	{
		curr = stack_a;
		put_ind_norm(curr, arr, &j);
		curr = stack_b;
		while (curr)
		{
			if (curr->value == arr[j])
			{
				curr->index = j++;
				break ;
			}
			curr = curr->next;
		}
	}
}

// Function: put_ind_norm 
// Description: Traverse a stack, and put the index of the number in the stack
// Input: t_node *stack - the linked list
// Output: int 
void	put_ind_norm(t_node *stack, int *arr, int *j)
{
	t_node	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->value == arr[*j])
		{
			curr->index = *j;
			*j += 1;
			break ;
		}
		curr = curr->next;
	}
}
