/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:32:53 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/11 21:07:06 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_isnum(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
