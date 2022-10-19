#include "push_swap.h"

// Function: fill_stack_a 
// Description: Take all the argument in av, transform them into int and put them in a linked list.
// Input: int ac - the number of arguments, char **av - the arguments
// Output: node * - the linked list
node *fill_stack_a(int ac, char **av)
{
  node *stack_a;
  node *curr;
  int i;

  stack_a = malloc(sizeof(node));
  stack_a->value = ft_atoi(av[1]);

  i = 2;
  stack_a->next = malloc(sizeof(node));
  curr = stack_a->next;
  while (av[i]) {
    curr->value = ft_atoi(av[i]);
    i++;
    if (!av[i])
      break;
    curr->next = malloc(sizeof(node));
    curr = curr->next;
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
    curr->index = i;
    if (!curr->next)
      break;
    curr = curr->next;
    i++;
  }
}

void put_index(node *stack) {
  node *curr;
  int i;

  curr = stack;
  i = 1;
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
    curr = curr->next;
  }
}

void push_swap(int ac, char **av) {
  node *stack_a;
  node *stack_b;
  stack_a = fill_stack_a(ac, av);
  put_pos(stack_a);
  print_stack(stack_a);
}

int main(int ac, char **av) {
  if (ac < 2)
    return (0);
  push_swap(ac, av);

  return (0);
}
