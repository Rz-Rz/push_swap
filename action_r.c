#include "push_swap.h"

// Function: ss
// Description: Swap the first two elements of stack_a and stack_b
// Input: node **stack_a - the stack to swap, node **stack_b - the stack to swap
// Output: void
void ss(node **stack_a, node **stack_b) 
{
  sa(stack_a);
  sb(stack_b);
}

// Function: rr
// Description: Rotate the stack_a and stack_b one element up.
// Input: node **stack_a - the stack to rotate, node **stack_b - the stack to
// Output: void
void rr(node **stack_a, node **stack_b) 
{
  ra(stack_a);
  rb(stack_b);
}

// Function: rrr
// Description: Rotate the stack_a and stack_b one element down.
// Input: node **stack_a - the stack to rotate, node **stack_b - the stack to
// Output: void
void rrr(node **stack_a, node **stack_b) 
{
  rra(stack_a);
  rrb(stack_b);
}
