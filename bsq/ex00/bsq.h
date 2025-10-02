/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugogarc <hugogarc@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:08:51 by hugogarc          #+#    #+#             */
/*   Updated: 2025/09/25 14:29:20 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map_info
{
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	full;
}	t_map_info;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

char		*read_file_to_string(int fd);

int			parse_first_line(char *str, t_map_info *info, int *offset);
char		**parse_map_grid(char *str, t_map_info *info, int offset);

int			is_map_valid(char **map_grid, t_map_info *info);
void		print_solution(char **map_grid, t_map_info *info, t_square *bsq);
void		print_map_error(void);

t_square	find_biggest_square(char **map_grid, t_map_info *info);

void		free_map_grid(char **grid, int height);
void		free_sol_grid(int **grid, int height);

#endif
