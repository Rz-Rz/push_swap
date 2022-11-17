/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:32:58 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/17 19:58:59 by kdhrif           ###   ########.fr       */
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

// Name: check_err_atoi
// Description: after the atoi function as worked, 
// check if there is anything that is not a number, 
// over is over the int max, or under the int min.
// Parameters: char *str - the string to check.
// Return: int - 0 if there is no error, 1 if there is an error.
int	check_err_atoi(char *nptr, long long nb)
{
	while (*nptr)
	{
		if (*nptr != ' ')
			return (1);
		nptr++;
	}
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}
