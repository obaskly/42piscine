/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogarc <hugogarc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:43:01 by hugogarc          #+#    #+#             */
/*   Updated: 2025/09/06 16:40:13 by hugogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_char(int row, int col, int x, int y)
{
	if (row == 1 || row == y)
	{
		if (col == 1)
			return ('A');
		if (col == x)
			return ('C');
		return ('B');
	}
	if (col == 1 || col == x)
		return ('B');
	return (' ');
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
	{
		ft_putchar('E');
		ft_putchar('R');
		ft_putchar('R');
		ft_putchar('O');
		ft_putchar('R');
		ft_putchar('\n');
		return ;
	}
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			ft_putchar(get_char(row, col, x, y));
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
