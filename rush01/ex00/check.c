/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <mochaouc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:30:14 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/13 12:30:23 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_views(int clues[16], int board[4][4])
{
	int	row[4];
	int	col[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row(i, board, clues, row))
			return (0);
		if (!check_column(i, board, clues, col))
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int i, int board[4][4], int clues[16], int row[4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		row[j] = board[i][j];
		j++;
	}
	if (count_visible(row) != clues[i + 8])
		return (0);
	j = 0;
	while (j < 4)
	{
		row[j] = board[i][3 - j];
		j++;
	}
	if (count_visible(row) != clues[i + 12])
		return (0);
	return (1);
}

int	check_column(int i, int board[4][4], int clues[16], int col[4])
{
	int	j;

	j = 0;
	while (j < 4)
	{
		col[j] = board[j][i];
		j++;
	}
	if (count_visible(col) != clues[i])
		return (0);
	j = 0;
	while (j < 4)
	{
		col[j] = board[3 - j][i];
		j++;
	}
	if (count_visible(col) != clues[i + 4])
		return (0);
	return (1);
}
