#include "push_swap.h"

// Function: swap
// Description: Swap two int
// Input: int *a - the first int, int *b - the second int
// Output: void
void swap(int *a, int *b) {
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

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

// Function: partition
// Description: Partition the array into two parts, choose the rightmost index as pivot, and distribute the smallest element to the left of the pivot and the largest element to the right of the pivot.
// Input: int *arr - the array to partition, int low - the lowest index, int high - the highest index
// Output: int - the index of the pivot
int partition(int *arr, int low, int high)
{
  int pivot;
  int i;
  int j;

  pivot = arr[high];
  i = low - 1;
  j = low;
  while (j < high) 
  {
	  if (arr[j] < pivot) 
	  {
		  i++;
		  swap(&arr[i], &arr[j]);
	  }
    j++;
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Function: quick_sort
// Description: Sorts a list using the quick sort algorithm
// Input: int *stack - the array to sort
//        int low - the lowest index of the list
//        int high - the highest index of the list
// Output: void
// Note: This function is recursive and call partition function to sort the list
void quick_sort(int *stack, int low, int high) {
  int pivot;

  if (low >= high) {
    pivot = partition(stack, low, high);
    quick_sort(stack, low, pivot - 1);
    quick_sort(stack, pivot + 1, high);
  }
}
