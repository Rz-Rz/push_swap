/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:32:58 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/17 13:50:41 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Name: error_clean
// Description : Free the stack and return NULL.
// Parameters: t_stack *stack - the stack to free.
// Return: NULL
t_node	*error_clean(t_node *stack, int error)
{
	if (stack)
		lst_free(stack);
	if (error)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	return (NULL);
}
//
// Name: error_clean
// Description : Free the stack and return NULL.
// Parameters: t_stack *stack - the stack to free.
// Return: NULL

int	error_clean_2(t_node *stack, int error)
{
	if (stack)
		lst_free(stack);
	if (error)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	return (-1);
}

// Name: fill_a_norm
// Description : Fill the stack_a with the arguments passed to the program.
// Parameters: char **argv - the arguments passed to the program.
// Return: t_node * - the stack_a.
// Note: This function is used in fill_stack_a function.
// Output: void
void	f(t_node *curr, t_node *stack_a, char **av, int *error)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		curr->value = ft_atoi(av[i], error);
		if (!av[i + 1])
			break ;
		curr->next = malloc(sizeof(t_node));
		if (!curr->next)
			error_clean(stack_a, 0);
		curr = curr->next;
	}
	curr->next = NULL;
}
