/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:29:24 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/14 20:24:40 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// Function: swap
// Description: Swap two int
// Input: int *a - the first int, int *b - the second int
// Output: void
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Function: t_nodeval_to_int
// Description: Take all the values from the t_node linked list and puts them in
// an int array. Input: t_node *stack - the list to take values from.
//        int ac - the argument count
// Output: int * - the int array.
int	*t_nodeval_to_int(t_node *stack_a, t_node *stack_b)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * (lst_size(stack_a) + lst_size(stack_b)));
	if (!arr)
		return (NULL);
	i = 0;
	while (stack_a)
	{
		arr[i] = stack_a->value;
		i++;
		stack_a = stack_a->next;
	}
	if (stack_b)
	{
		while (stack_b)
		{
			arr[i] = stack_b->value;
			i++;
			stack_b = stack_b->next;
		}
	}
	return (arr);
}

// Function: partition
// Description: Partition the array into two parts,
// Input: int *arr - the array to partition, int low - the lowest index,
//	int high - the highest index
// Output: int - the index of the pivot
int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

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
void	quick_sort(int *stack, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(stack, low, high);
		quick_sort(stack, low, pivot - 1);
		quick_sort(stack, pivot + 1, high);
	}
}

// Function: put_index
// Description: Put the index, the place the number should have,
// in the linked list.
// Input: t_node *stack_a - the linked list
//       t_node *stack_b - the linked list
// Output: void
void	put_index(t_node *stack_a, t_node *stack_b)
{
	int	j;
	int	*arr;
	int	ac;

	ac = lst_size(stack_a) + lst_size(stack_b);
	j = 0;
	arr = t_nodeval_to_int(stack_a, stack_b);
	quick_sort(arr, 0, ac - 1);
	put_index_bis(stack_a, stack_b, ac, j, arr);
	free(arr);
}
