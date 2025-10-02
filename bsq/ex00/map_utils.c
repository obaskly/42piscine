/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogarc <hugogarc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:22 by hugogarc          #+#    #+#             */
/*   Updated: 2025/09/25 14:10:24 by hugogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_map_valid(char **map_grid, t_map_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		if (ft_strlen(map_grid[y]) != info->width)
			return (0);
		x = 0;
		while (x < info->width)
		{
			if (map_grid[y][x] != info->empty
				&& map_grid[y][x] != info->obstacle)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	print_solution(char **map_grid, t_map_info *info, t_square *bsq)
{
	int	y;
	int	x;

	y = bsq->y;
	while (y < bsq->y + bsq->size)
	{
		x = bsq->x;
		while (x < bsq->x + bsq->size)
		{
			map_grid[y][x] = info->full;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < info->height)
	{
		write(1, map_grid[y], info->width);
		write(1, "\n", 1);
		y++;
	}
}

void	print_map_error(void)
{
	write(2, "map error\n", 10);
}
