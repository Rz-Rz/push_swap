#include "push_swap.h"

// Function: nodeval_to_int
// Description: Take all the values from the node linked list and puts them in
// an int array. Input: node *stack - the list to take values from.
//        int ac - the argument count
// Output: int * - the int array.
int *nodeval_to_int(node *stack, int ac) {
  int *arr;
  int i;

  arr = malloc(sizeof(int) * ac);
  if (!arr)
    return (NULL);
  i = 0;
  while (stack && stack->next) {
    arr[i] = stack->value;
    i++;
    stack = stack->next;
  }
  return (arr);
}

// Function: quick_sort
// Description: Sorts a list using the quick sort algorithm
// Input: node *stack - the list to sort
//        int low - the lowest index of the list
//        int high - the highest index of the list
// Output: void
// Note: This function is recursive
void quick_sort(node *stack, int low, int high) {
  int pi;

  if (low < high) {
    pi = partition(high, low, stack);
    quick_sort(stack, low, pi - 1);
    quick_sort(stack, pi + 1, high);
  }
}
