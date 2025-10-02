/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <mochaouc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:30:57 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/13 12:30:59 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	clues[16];
	int	board[4][4];

	if (argc != 2 || !parse_input(argv[1], clues))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_create_table(clues, board))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_board(board);
	return (0);
}
