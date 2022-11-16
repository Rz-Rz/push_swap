/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:32:58 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/16 15:15:47 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <wchar.h>

// Name: error_clean
// Description : Free the stack and return NULL.
// Parameters: t_stack *stack - the stack to free.
// Return: NULL
t_node	*error_clean(t_node *stack)
{
	if (stack)
		lst_free(stack);
	return (NULL);
}
