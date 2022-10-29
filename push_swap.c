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

// Function: put_pos
// Description: Put the position of each node in the linked list
// Input: node *stack - the linked list
// Output: void
void put_pos(node *stack)
{
  node *curr;
  int i;

  curr = stack;
  i = 1;
  while (curr) {
    curr->pos = i;
    if (!curr->next)
      break;
    curr = curr->next;
    i++;
  }
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
    /* printf("index : %d\n", curr->index); */
    /* printf("pos : %d\n", curr->pos); */
    curr = curr->next;
  }
}

int push_swap(int ac, char **av) {
	node *stack_a;
	/* node *stack_b; */
	/* stack_b = NULL; */
	stack_a = fill_stack_a(av);
	if (stack_a == NULL)
		return  (-1);
	put_pos(stack_a);
	put_index(stack_a, ac);
	print_stack(stack_a);
	printf("RA\n");
	ra(&stack_a);
	print_stack(stack_a);
	printf("RRA\n");
	rra(&stack_a);
	print_stack(stack_a);

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
