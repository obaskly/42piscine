/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:12:43 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/23 16:00:24 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 32 && c <= 126)
		{
			write(1, &c, 1);
		}
		else
		{
			write(1, "\\", 1);
			write(1, &("0123456789abcdef"[c / 16]), 1);
			write(1, &("0123456789abcdef"[c % 16]), 1);
		}
		i++;
	}
}
