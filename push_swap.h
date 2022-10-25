#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define NULL ((char *)0)
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *next;
  int value;
  int index;
  int pos;
  int target_pos;
  int cost_a;
  int cost_b;
} node;

// linked_list_0.c
node *lst_new(int value);
node *lst_duplicate(node *stack);
void lst_add_back(node **stack, node *new_node);
void lst_swap(node *n1, node *n2);
node *lst_last(node *stack);

// linked_list_1.c
void lst_free(node *head);

// push_swap.c
node *fill_stack_a(int ac, char **av);
void put_pos(node *stack);
void print_stack(node *stack);

// sorting.c
void quick_sort(int *stack, int low, int high);
int partition(int *arr, int low, int high);
int *nodeval_to_int(node *stack, int ac);
void swap(int *a, int *b);
void put_index(node *stack, int ac);

// parsing.c
int is_ordered(node *stack);
int is_duplicate(node *stack);

// action_b.c
void sb(node **stack_b);
void rb(node **stack_b);
void pb(node **stack_a, node **stack_b);
void rrb(node **stack_b);

// action_a.c
void rra(node **stack_a);
void ra(node **stack_a);
void sa(node **stack_a);
void pa(node **stack_a, node **stack_b);

// action_r.c

// ft_utils.c
int ft_atoi(const char *nptr, int *error);

#endif
