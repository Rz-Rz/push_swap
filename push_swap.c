/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:08:20 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/11 21:25:00 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: fill_stack_a
// Description: Take all the argument in av, transform them into int and put
// them in a linked list. Input: int ac - the number of arguments, char **av -
// the arguments Output: node * - the linked list
node	*fill_stack_a(char **av)
{
	node	*stack_a;
	node	*curr;
	int		i;
	int		error;

	error = 0;
	i = 0;
	stack_a = malloc(sizeof(node));
	curr = stack_a;
	while (av[i])
	{
		curr->value = ft_atoi(av[i], &error);
		i++;
		if (!av[i])
			break ;
		curr->next = malloc(sizeof(node));
		curr = curr->next;
	}
	curr->next = NULL;
	error += is_duplicate(stack_a);
	if (error)
	{
		lst_free(stack_a);
		return (NULL);
	}
	return (stack_a);
}

// Function: print_stack
// Description: Print the values of the linked list
// Input: node *stack - the linked list
// Output: void
void	print_stack(node *stack)
{
	node	*curr;

	if (!stack)
	{
		printf("stack is empty");
		return ;
	}
	curr = stack;
	while (curr)
	{
		printf("value : %d\n", curr->value);
		printf("index : %d\n", curr->index);
		printf("pos : %d\n", curr->pos);
		printf("cost_a : %d\n", curr->cost_a);
		printf("cost_b : %d\n", curr->cost_b);
		printf("target pos : %d\n", curr->target_pos);
		printf("--- node end ---\n");
		curr = curr->next;
	}
}

void	print_node(node *n)
{
	node	*curr;

	if (!n)
	{
		printf("stack is empty");
		return ;
	}
	curr = n;
	printf("value : %d\n", curr->value);
	printf("index : %d\n", curr->index);
	printf("pos : %d\n", curr->pos);
	printf("cost_a : %d\n", curr->cost_a);
	printf("cost_b : %d\n", curr->cost_b);
	printf("target pos : %d\n", curr->target_pos);
	printf("--- node end ---\n");
}

int	push_swap(int ac, char **av)
{
	node	*stack_a;
	node	*stack_b;

	stack_b = NULL;
	stack_a = fill_stack_a(av);
	if (stack_a == NULL)
		return (-1);
	if (ac == 2)
		sort_2(&stack_a);
	else if (ac == 3)
		sort_3(&stack_a);
	else if (ac > 3 && ac < 501)
		sort(&stack_a, &stack_b);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	char	**parsed_av;

	i = 0;
	if (ac < 2)
		return (0);
	parsed_av = master_parser(av);
	while (parsed_av[i])
		i++;
	ac = i;
	i = push_swap(ac, parsed_av);
	if (i == -1)
		ft_printf("Error\n");
	return (0);
}
