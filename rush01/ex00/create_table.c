/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <mochaouc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:30:30 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/13 12:30:33 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_create_table(int clues[16], int board[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	return (solve_recursive(clues, board, 0));
}

int	solve_recursive(int clues[16], int board[4][4], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_views(clues, board));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(board, row, col, num))
		{
			board[row][col] = num;
			if (solve_recursive(clues, board, pos + 1))
				return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	print_board(int board[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = board[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
