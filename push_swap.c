#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// this function will take in all the argument in av and fill stack_a as linked
// list.
node *fill_stack_a(int ac, char **av) {
  node *stack_a;
  node *curr;
  int i;

  stack_a = malloc(sizeof(node));
  stack_a->value = ft_atoi(av[1]);

  i = 2;
  stack_a->next = malloc(sizeof(node));
  curr = stack_a->next;
  while (i < ac) {
    curr->value = ft_atoi(av[i]);
    curr->next = malloc(sizeof(node));
    curr = curr->next;
    i++;
  }
  return (stack_a);
}

void print_stack_a(node *stack_a) {
  node *curr;
  curr = stack_a;
  while (curr) {
    printf("%d", curr->value);
    curr = curr->next;
  }
}

void push_swap(int ac, char **av) {
  node *stack_a;
  stack_a = fill_stack_a(ac, av);
}

int main(int ac, char **av) {
  push_swap(ac, av);

  return (0);
}
