/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogarc <hugogarc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:10:11 by hugogarc          #+#    #+#             */
/*   Updated: 2025/09/25 14:10:13 by hugogarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_map(int fd)
{
	t_map_info	info;
	t_square	bsq;
	char		*map_str;
	char		**map_grid;
	int			offset;

	map_str = read_file_to_string(fd);
	if (!map_str)
		return (print_map_error());
	if (!parse_first_line(map_str, &info, &offset))
	{
		free(map_str);
		return (print_map_error());
	}
	map_grid = parse_map_grid(map_str, &info, offset);
	free(map_str);
	if (!map_grid || !is_map_valid(map_grid, &info))
	{
		if (map_grid)
			free_map_grid(map_grid, info.height);
		return (print_map_error());
	}
	bsq = find_biggest_square(map_grid, &info);
	print_solution(map_grid, &info, &bsq);
	free_map_grid(map_grid, info.height);
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc == 1)
		process_map(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
				print_map_error();
			else
			{
				process_map(fd);
				close(fd);
			}
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
