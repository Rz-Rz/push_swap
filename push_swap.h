#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#define NULL ((char *)0)
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *next;
  struct node *prev;
  int value;
  int index;
  int pos;
  int target_pos;
  int cost_a;
  int cost_b;
} node;

//linked_list.c 
node *lst_new(int value);
node *lst_duplicate(node *stack);
void lst_add_back(node **stack, node *new_node);

//push_swap.c
node *fill_stack_a(int ac, char **av); 
void put_pos(node *stack);
void print_stack(node *stack);





int ft_atoi(const char *nptr);

#endif
