#include "push_swap.h"

int partition(int high, int low, node *stack)
{
    int pivot = stack->value;
    int i = (low - 1);
    int j;
    int temp;

    for (j = low; j <= high - 1; j++)
    {
	if (stack->value <= pivot)
	{
	    i++;
	    temp = stack->value;
	    stack->value = stack->value;
	    stack->value = temp;
	}
    }
    temp = stack->value;
    stack->value = stack->value;
    stack->value = temp;
    return (i + 1);
}

// Function: quick_sort
// Description: Sorts a list using the quick sort algorithm
// Input: node *stack - the list to sort
//        int low - the lowest index of the list
//        int high - the highest index of the list
// Output: void
// Note: This function is recursive
void quick_sort(node *stack, int low, int high)
{
    int pi;

    if (low < high)
    {
	pi = partition(high, low, stack);
	quick_sort(stack, low, pi - 1);
	quick_sort(stack, pi + 1, high);
    }
}
