/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:28:26 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/13 21:28:27 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: lst_duplicate
// Description: Duplicates a list
// Input: t_node *stack - the list to duplicate
// Output: t_node * - the duplicate list
t_node	*lst_duplicate(t_node *stack)
{
	t_node	*new_stack;
	t_node	*tmp;

	new_stack = NULL;
	while (stack)
	{
		tmp = lst_new(stack->value);
		lst_add_back(&new_stack, tmp);
		stack = stack->next;
	}
	return (new_stack);
}

// Function: lst_new
// Description: Creates a new t_node
// Input: int value - the data to store in the t_node
// Output: t_node * - the new t_node
// Note: The new t_node is created with a NULL next pointer
t_node	*lst_new(int value)
{
	t_node	*new_t_node;

	new_t_node = (t_node *)malloc(sizeof(t_node));
	if (!new_t_node)
		return (NULL);
	new_t_node->value = value;
	new_t_node->next = NULL;
	return (new_t_node);
}

// Function: lst_add_back
// Description: Adds a t_node to the end of a list
// Input: t_node **stack - the list to add to
//       t_node *new_t_node - the t_node to add
// Output: void
void	lst_add_back(t_node **stack, t_node *new_t_node)
{
	t_node	*tmp;

	if (!*stack)
		*stack = new_t_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_t_node;
	}
}

// Function: lst_swap_values
// Description: Swaps the two t_nodes in a list
// Input: t_node *n1  - the t_node to swap with
//      t_node *n2 - the t_node to swap with
// Output: void
void	lst_swap(t_node *n1, t_node *n2)
{
	int	tmp;

	tmp = n1->value;
	n1->value = n2->value;
	n2->value = tmp;
}

// Function: lst_last
// Description: Returns the last t_node in a list
// Input: t_node *stack - the list to search
// Output: t_node * - the last t_node in the list
t_node	*lst_last(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
