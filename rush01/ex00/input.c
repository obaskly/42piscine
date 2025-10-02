/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <mochaouc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:30:46 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/13 12:30:50 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_space(char c)
{
	return (c == ' ');
}

int	is_digit(char c)
{
	return (c >= '1' && c <= '4');
}

int	parse_input(char *str, int *clues)
{
	int	i;
	int	n;
	int	count;

	i = 0;
	n = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (is_digit(str[i]) == 1 && (i % 2 == 0))
		{
			clues[n] = str[i] - '0';
			count++;
			n++;
		}
		else if (is_space(str[i]) == 1 && (i % 2 == 1))
			count++;
		i++;
	}
	if (count != 31)
		return (0);
	return (1);
}
