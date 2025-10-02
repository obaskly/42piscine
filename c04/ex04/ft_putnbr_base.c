/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:08:52 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/22 15:32:09 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i])
	{
		if (c[i] == '+' || c[i] == '-')
			return (0);
		j = i + 1;
		while (c[j])
		{
			if (c[j] == c[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void    ft_putnbr_base(int nbr, char *base)
{
    int         base_len;
    long int    n;

    base_len = check_base(base);
    if (base_len == 0)
        return;
    n = nbr;
	if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
    ft_putchar(base[n % base_len]);
}
