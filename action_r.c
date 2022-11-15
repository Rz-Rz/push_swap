/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:28:48 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/15 15:37:33 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: ss
// Description: Swap the first two elements of stack_a and stack_b
// Input: t_node **stack_a - the stack to swap, / 
// t_node **stack_b - the stack to swap
// Output: void
void	ss(t_node **stack_a, t_node **stack_b, int toggle)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (toggle)
		ft_printf("ss\n");
}

// Function: rr
// Description: Rotate the stack_a and stack_b one element up.
// Input: t_node **stack_a - the stack to rotate, / 
// t_node **stack_b - the stack to
// Output: void
void	rr(t_node **stack_a, t_node **stack_b, int toggle)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (toggle)
		ft_printf("rr\n");
}

// Function: rrr
// Description: Rotate the stack_a and stack_b one element down.
// Input: t_node **stack_a - the stack to rotate, / 
// t_node **stack_b - the stack to
// Output: void
void	rrr(t_node **stack_a, t_node **stack_b, int toggle)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (toggle)
		ft_printf("rrr\n");
}
