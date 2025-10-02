/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogarc <hugogarc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:49 by hugogarc          #+#    #+#             */
/*   Updated: 2025/09/25 14:10:53 by hugogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min_of_three(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

int	**create_sol_grid(int height, int width)
{
	int	**grid;
	int	i;

	grid = malloc(sizeof(int *) * height);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < height)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (!grid[i])
		{
			free_sol_grid(grid, i);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	process_cell(int **sol_grid, int y, int x, t_square *bsq)
{
	int	min_neighbor;

	if (y == 0 || x == 0)
		sol_grid[y][x] = 1;
	else
	{
		min_neighbor = min_of_three(sol_grid[y - 1][x],
				sol_grid[y][x - 1], sol_grid[y - 1][x - 1]);
		sol_grid[y][x] = 1 + min_neighbor;
	}
	if (sol_grid[y][x] > bsq->size)
	{
		bsq->size = sol_grid[y][x];
		bsq->x = x - bsq->size + 1;
		bsq->y = y - bsq->size + 1;
	}
}

t_square	process_grid(
	char **map_grid,
	int **sol_grid,
	t_map_info *info,
	t_square *bsq
)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (map_grid[y][x] == info->obstacle)
				sol_grid[y][x] = 0;
			else
				process_cell(sol_grid, y, x, bsq);
			x++;
		}
		y++;
	}
	return (*bsq);
}

t_square	find_biggest_square(char **map_grid, t_map_info *info)
{
	t_square	bsq;
	int			**sol_grid;

	bsq.size = 0;
	bsq.x = 0;
	bsq.y = 0;
	sol_grid = create_sol_grid(info->height, info->width);
	if (!sol_grid)
		return (bsq);
	bsq = process_grid(map_grid, sol_grid, info, &bsq);
	free_sol_grid(sol_grid, info->height);
	return (bsq);
}
