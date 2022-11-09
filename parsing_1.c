/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:54:54 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/09 20:13:44 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function: master_parser
// Description: Take the av and split it using ft_split function 
// input: char **av
// output: char **
char	**master_parser(int ac, char **av)
{
	char	**split;

	if (ac == 2) 
		split = ft_split(av[1], ' ');
	else
		return(av);
	return (split);
}
