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
// Input: node *stack - the list to duplicate
// Output: node * - the duplicate list
node	*lst_duplicate(node *stack)
{
	node	*new_stack;
	node	*tmp;

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
// Description: Creates a new node
// Input: int value - the data to store in the node
// Output: node * - the new node
// Note: The new node is created with a NULL next pointer
node	*lst_new(int value)
{
	node	*new_node;

	new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

// Function: lst_add_back
// Description: Adds a node to the end of a list
// Input: node **stack - the list to add to
//       node *new_node - the node to add
// Output: void
void	lst_add_back(node **stack, node *new_node)
{
	node	*tmp;

	if (!*stack)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

// Function: lst_swap_values
// Description: Swaps the two nodes in a list
// Input: node *n1  - the node to swap with
//      node *n2 - the node to swap with
// Output: void
void	lst_swap(node *n1, node *n2)
{
	int	tmp;

	tmp = n1->value;
	n1->value = n2->value;
	n2->value = tmp;
}

// Function: lst_last
// Description: Returns the last node in a list
// Input: node *stack - the list to search
// Output: node * - the last node in the list
node	*lst_last(node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
