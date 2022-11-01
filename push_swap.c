/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:08:20 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/01 16:20:17 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function: fill_stack_a 
// Description: Take all the argument in av, transform them into int and put them in a linked list.
// Input: int ac - the number of arguments, char **av - the arguments
// Output: node * - the linked list
node *fill_stack_a(char **av)
{
  node *stack_a;
  node *curr;
  int i;
  int error;

  error = 0;
  stack_a = malloc(sizeof(node));
  stack_a->value = ft_atoi(av[1], &error);
  i = 2;
  stack_a->next = malloc(sizeof(node));
  curr = stack_a->next;
  while (av[i]) {
    curr->value = ft_atoi(av[i], &error);
    i++;
    if (!av[i])
      break;
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
void print_stack(node *stack) 
{
  node *curr;
  if (!stack) {
    printf("stack is empty");
    return;
  }
  curr = stack;
  while (curr) {
    printf("value : %d\n", curr->value);
    printf("index : %d\n", curr->index);
    printf("pos : %d\n", curr->pos);
    printf("target pos : %d\n", curr->target_pos);
    printf("--- node end ---\n");
    curr = curr->next;
  }
}

int push_swap(int ac, char **av) {
	node *stack_a;
	node *stack_b;
	stack_b = NULL;
	stack_a = fill_stack_a(av);
	if (stack_a == NULL)
		return  (-1);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	put_pos(stack_a, stack_b);
	put_index(stack_a, stack_b);
	put_target_pos(stack_b, stack_a);
	printf("stack_a\n");
	print_stack(stack_a);
	printf("---stack_b---\n");
	print_stack(stack_b);
	if (ac == 3)
		sort_2(&stack_a);
	else if (ac == 4)
		sort_3(&stack_a);

	return (1);
}

int main(int ac, char **av) {
	int i = 0;
	if (ac < 2)
		return (0);
	i = push_swap(ac, av);
	if (i == -1)
		printf("Error\n");

	return (0);
}
