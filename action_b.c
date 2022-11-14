/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:44:41 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/14 20:24:20 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Function pb
// Description: Push the first element of stack_a to stack_b
// Input: t_node **stack_a - the stack to push from, t_node **stack_b - the stack to
// push to Output: void
void	pb(t_node **stack_a, t_node **stack_b, int toggle)
{
	t_node	*tmp;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (toggle)
		ft_printf("pb\n");
}

// Function sb
// Description: Swap the first two elements of stack_b
// Input: t_node **stack_b - the stack to swap
// Output: void
void	sb(t_node **stack_b, int toggle)
{
	t_node	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (toggle)
		ft_printf("sb\n");
}

// Function rb
// Description: Rotate the stack_b one element up.
// Input: t_node **stack_b - the stack to rotate
// Output: void
void	rb(t_node **stack_b, int toggle)
{
	t_node	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next->next = NULL;
	if (toggle)
		ft_printf("rb\n");
}

/* Function rrb
// Description: Rotate the stack_b one element down.
// Input: t_node **stack_b - the stack to rotate
// Output: void */
void	rrb(t_node **stack_b, int toggle)
{
	t_node	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (toggle)
		ft_printf("rrb\n");
}
