/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <mochaouc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:01:50 by mochaouc          #+#    #+#             */
/*   Updated: 2025/10/02 18:01:50 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

int	parse_input(char *str, int *clues);
int	ft_create_table(int clues[16], int board[4][4]);
void	print_board(int board[4][4]);

int	is_space(char c);
int	is_digit(char c);
int	solve_recursive(int clues[16], int board[4][4], int pos);
int	check_views(int clues[16], int board[4][4]);
int	check_row(int i, int board[4][4], int clues[16], int row[4]);
int	check_column(int i, int board[4][4], int clues[16], int col[4]);
int	is_valid(int board[4][4], int row, int col, int num);
int	count_visible(int *line);

#endif
