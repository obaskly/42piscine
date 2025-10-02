/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <mochaouc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:31:06 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/13 12:31:07 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid(int board[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[row][i] == num || board[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	max = line[0];
	count = 1;
	i = 1;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}
