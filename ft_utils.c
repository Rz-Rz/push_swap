/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:27:40 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/10 18:03:18 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Function: ft_atoi 
// Description: Converts a string to an integer. Modify an int pointer is the input is invalid.
// Parameters: char *str - the string to convert.
//             int *error - pointer to an int to modify if the input is invalid.
// Return: The integer value of the string.
int ft_atoi(const char *nptr, int *error) 
{
  long long nb;
  int neg;

  nb = 0;
  neg = 0;
  while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
    nptr++;
  if (*nptr == '-' || *nptr == '+')
    if (*nptr++ == '-')
      neg++;
  while (*nptr >= '0' && *nptr <= '9')
    nb = nb * 10 + *nptr++ - '0';
  if (neg)
    nb *= -1;
  if (*nptr != '\0')
	  *error = 1;
  if (nb > 2147483647 || nb < -2147483648)
	  *error = 1;
  return ((int)nb);
}

// Function: ft_abs
// Description: Returns the absolute value of an integer.
// Parameters: int nb - the integer to convert.
// Return: The absolute value of the integer.
int ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

// Function: ft_strdup
// Description: Duplicates a string.
// Parameters: char *str - the string to duplicate.
// Return: The duplicated string.
char *ft_strdup(char *str)
{
	char *dup;
	int i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
