/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:44:27 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/14 18:44:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Function: is_ordered
// Description: Checks if the stack is in correct order.
// Return: 1 if ordered, 0 if not.
// Parameters: t_node *stack
int	is_ordered(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Function: is_duplicate
// Description: Checks if the stack contains duplicates.
// Return: 1 if duplicate, 0 if not.
// Parameters: t_node *stack
int	is_duplicate(t_node *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

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
