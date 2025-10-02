/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogarc <hugogarc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:40 by hugogarc          #+#    #+#             */
/*   Updated: 2025/09/25 14:10:43 by hugogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str, int *i)
{
	int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

int	parse_first_line(char *str, t_map_info *info, int *offset)
{
	int	i;

	i = 0;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	info->height = ft_atoi(str, &i);
	if (info->height == 0 || str[i] == '\0' || str[i + 1] == '\0'
		|| str[i + 2] == '\0' || str[i + 3] != '\n')
		return (0);
	info->empty = str[i];
	info->obstacle = str[i + 1];
	info->full = str[i + 2];
	if (info->empty == info->obstacle || info->empty == info->full
		|| info->obstacle == info->full)
		return (0);
	*offset = i + 4;
	return (1);
}

int	get_width(char *str, int offset)
{
	int	width;

	width = 0;
	while (str[offset + width] != '\n' && str[offset + width] != '\0')
		width++;
	return (width);
}

char	**create_map_grid(int height, int width)
{
	char	**grid;
	int		y;

	grid = malloc(sizeof(char *) * height);
	if (!grid)
		return (NULL);
	y = 0;
	while (y < height)
	{
		grid[y] = malloc(sizeof(char) * (width + 1));
		if (!grid[y])
		{
			free_map_grid(grid, y);
			return (NULL);
		}
		y++;
	}
	return (grid);
}

char	**parse_map_grid(char *str, t_map_info *info, int offset)
{
	char	**grid;
	int		y;
	int		x;

	info->width = get_width(str, offset);
	if (info->width <= 0)
		return (NULL);
	grid = create_map_grid(info->height, info->width);
	if (!grid)
		return (NULL);
	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			grid[y][x] = str[offset + x];
			x++;
		}
		grid[y][x] = '\0';
		offset += info->width + 1;
		y++;
	}
	return (grid);
}
