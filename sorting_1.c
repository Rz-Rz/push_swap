/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:52:13 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/13 21:50:49 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: put_index_bis
// Description: Put the index, the place the number should have,
//	in the linked list.
// Input: node *stack_a - the linked list
//       node *stack_b - the linked list
// Output: void
void	put_index_bis(node *stack_a, node *stack_b, int ac, int j, int *arr)
{
	node	*curr;

	while (j < ac)
	{
		curr = stack_a;
		while (curr)
		{
			if (curr->value == arr[j])
			{
				curr->index = j++;
				break ;
			}
			curr = curr->next;
		}
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
