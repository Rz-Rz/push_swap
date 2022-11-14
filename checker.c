/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:26:12 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/14 17:05:56 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "push_swap.h"

// Function: checker
// Description: parse the input from stdin with get_next_line, fill the stack_a,
//	with fill_stack_a function,
//	and execute each instruction. Then check if the stack_a is sorted.
// Input: char **argv - the arguments passed to the program.
// Output: int - 0 if the stack_a is sorted, -1 if there is an error.
int	checker(char **argv)
{
	node	*stack_a;
	node	*stack_b;
	char	*line;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (argv[i])
		i++;
	stack_a = fill_stack_a(argv);
	if (stack_a == NULL)
		return (-1);
	line = get_next_line(0);
	while (line)
	{
		if (execute_instruction(line, &stack_a, &stack_b) == -1)
			return (-1);
		free(line);
		line = get_next_line(0);
	}
	if (is_ordered(stack_a) == 1)
					ft_printf("OK\n");
	lst_free(stack_a);
	return (1);
}

// Function: execute_instruction
// Description: execute the passed instruction.
// Input: char *line - the instruction to execute.
//      node **stack_a - the stack_a.
//      node **stack_b - the stack_b.
//      int *i - the number of instructions executed.
// Output: int - 0 if the instruction is valid, -1 if there is an error.
int	execute_instruction(char *line, node **stack_a, node **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (-1);
	return (0);
}

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
	i = -1;
	stack_a = malloc(sizeof(node));
	curr = stack_a;
	while (av[++i])
	{
		curr->value = ft_atoi(av[i], &error);
		if (!av[i + 1])
			break ;
		curr->next = malloc(sizeof(node));
		curr = curr->next;
	}
	curr->next = NULL;
	error += is_duplicate(stack_a);
	free_str(av);
	if (error)
	{
		lst_free(stack_a);
		return (NULL);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	int		i;
	char	**parsed_av;

	if (ac < 2)
		return (0);
	parsed_av = master_parser(av);
	i = checker(parsed_av);
	if (i == -1)
		ft_printf("KO\n");
	return (0);
}
