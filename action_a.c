/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:43:50 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/14 18:53:37 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Function pa
// Description: Push the first element of stack_b to stack_a
// Input: t_node **stack_a - the stack to push to, t_node **stack_b - the stack to
// push from Output: void
void	pa(t_node **stack_a, t_node **stack_b, int toggle)
{
	t_node	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (toggle)
		ft_printf("pa\n");
}

// Function sa
// Description: Swap the first two elements of stack_a
// Input: t_node **stack_a - the stack to swap
// Output: void
void	sa(t_node **stack_a, int toggle)
{
	t_node	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (toggle)
		ft_printf("sa\n");
}

// Function ra
// Description: Rotate the stack_a one element up.
// Input: t_node **stack_a - the stack to rotate
// Output: void
void	ra(t_node **stack_a, int toggle)
{
	t_node	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next->next = NULL;
	if (toggle)
		ft_printf("ra\n");
}

/* Function rra
// Description: Rotate the stack_a one element down.
// Input: t_node **stack_a - the stack to rotate
// Output: void */
void	rra(t_node **stack_a, int toggle)
{
	t_node	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (toggle)
		ft_printf("rra\n");
}
