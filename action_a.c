#include "push_swap.h"

// Function pa
// Description: Push the first element of stack_b to stack_a
// Input: node **stack_a - the stack to push to, node **stack_b - the stack to
// push from Output: void
void pa(node **stack_a, node **stack_b) {
  node *tmp;

  if (!(*stack_b))
    return;
  tmp = *stack_b;
  *stack_b = (*stack_b)->next;
  tmp->next = *stack_a;
  *stack_a = tmp;
  ft_printf("pa\n");
}

// Function sa
// Description: Swap the first two elements of stack_a
// Input: node **stack_a - the stack to swap
// Output: void
void sa(node **stack_a) {
  node *tmp;

  if (!(*stack_a) || !(*stack_a)->next)
    return;
  tmp = (*stack_a)->next;
  (*stack_a)->next = tmp->next;
  tmp->next = *stack_a;
  *stack_a = tmp;
  ft_printf("sa\n");
}

// Function ra
// Description: Rotate the stack_a one element up.
// Input: node **stack_a - the stack to rotate
// Output: void
void ra(node **stack_a) {
  node *tmp;

  if (!(*stack_a) || !(*stack_a)->next)
    return;
  tmp = *stack_a;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = *stack_a;
  *stack_a = (*stack_a)->next;
  tmp->next->next = NULL;
  ft_printf("ra\n");
}

// Function rra
// Description: Rotate the stack_a one element down.
// Input: node **stack_a - the stack to rotate
// Output: void
void rra(node **stack_a) {
  node *tmp;

  if (!(*stack_a) || !(*stack_a)->next)
    return;
  tmp = *stack_a;
  while (tmp->next->next)
    tmp = tmp->next;
  tmp->next->next = *stack_a; // *stack_a is now the second element. 
  *stack_a = tmp->next; // *stack_a is assigned to what used to be the last element, which is now the first.
  tmp->next = NULL; // What used to point to the last element, now points to NULL, as the new last element.
  ft_printf("rra\n");
}
