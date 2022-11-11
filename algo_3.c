#include "push_swap.h"

// Function: r_actions_same_sign
// Description: use the rr or rrr actions when the cost_a and b have the same
// sign. input: node **stack_a
//        node **stack_b
//        node *to_sort
// output : void
void r_actions_same_sign(node **stack_a, node **stack_b, node *to_sort)
{
    if (to_sort->cost_a < 0 && to_sort->cost_b < 0)
    {
	while (to_sort->cost_a < 0 && to_sort->cost_b < 0)
	{
	    rrr(stack_a, stack_b, 1);
	    to_sort->cost_a++;
	    to_sort->cost_b++;
	}
    }
    else if (to_sort->cost_a > 0 && to_sort->cost_b > 0)
    {
	while (to_sort->cost_a > 0 && to_sort->cost_b > 0)
	{
	    rr(stack_a, stack_b, 1);
	    to_sort->cost_a--;
	    to_sort->cost_b--;
	}
    }
}


// Function: median_sorter
// Description: Push the elements of the stack_a if their index is smaller than the median of all the elements of the stack_a. If they are not smaller than we ra.
// input: node **stack_a
//       node **stack_b
//       int median
// output: void
void median_sorter(node **stack_a, node **stack_b, int median, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
	if ((*stack_a)->index < median)
	    pb(stack_a, stack_b);
	else
	    ra(stack_a, 1);
	i++;
    }
}
