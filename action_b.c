#include "push_swap.h"

// Function pb
// Description: Push the first element of stack_a to stack_b
// Input: node **stack_a - the stack to push from, node **stack_b - the stack to
// push to Output: void
void pb(node **stack_a, node **stack_b) {
  node *tmp;

  if (!(*stack_a))
    return;
  tmp = *stack_a;
  *stack_a = (*stack_a)->next;
  tmp->next = *stack_b;
  *stack_b = tmp;
  ft_printf("pb\n");
}

// Function sb
// Description: Swap the first two elements of stack_b
// Input: node **stack_b - the stack to swap
// Output: void
void sb(node **stack_b) {
  node *tmp;

  if (!(*stack_b) || !(*stack_b)->next)
    return;
  tmp = (*stack_b)->next;
  (*stack_b)->next = tmp->next;
  tmp->next = *stack_b;
  *stack_b = tmp;
  ft_printf("sb\n");
}

// Function rb
// Description: Rotate the stack_b one element up.
// Input: node **stack_b - the stack to rotate
// Output: void
void rb(node **stack_b) {
  node *tmp;

  if (!(*stack_b) || !(*stack_b)->next)
    return;
  tmp = *stack_b;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = *stack_b;
  *stack_b = (*stack_b)->next;
  tmp->next->next = NULL;
  ft_printf("rb\n");
}

// Function rrb
// Description: Rotate the stack_b one element down.
// Input: node **stack_b - the stack to rotate
// Output: void
void rrb(node **stack_b) {
  node *tmp;

  if (!(*stack_b) || !(*stack_b)->next)
    return;
  tmp = *stack_b;
  while (tmp->next->next)
    tmp = tmp->next;
  tmp->next->next = *stack_b; // *stack_b is now the second element. 
  *stack_b = tmp->next; // *stack_b is assigned to what used to be the last element, which is now the first.
  tmp->next = NULL; // What used to point to the last element, now points to NULL, as the new last element.
  ft_printf("rrb\n");
}
