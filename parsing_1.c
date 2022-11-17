/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:54:54 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/17 21:14:55 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// function: master_parser
// Description: Take the av, strjoin everything starting at av[1],
//	then split it using ft_split function
// input: char **av
// output: char **
char	**master_parser(char **av)
{
	char	*str;
	char	**tab;
	char	*tmp;
	int		i;

	i = 1;
	str = ft_strdup(av[1]);
	while (av[i + 1])
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, av[i + 1]);
		free(tmp);
		i++;
	}
	tab = ft_split(str, ' ');
	free(str);
	return (tab);
}
