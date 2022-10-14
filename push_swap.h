#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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

int ft_atoi(const char *nptr);

#endif
