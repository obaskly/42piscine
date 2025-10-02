/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:03:04 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/02 14:03:08 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	temporary;

	a = 0;
	b = size - 1;
	while (a < b)
	{
		temporary = tab[a];
		tab[a] = tab[b];
		tab[b] = temporary;
		a++;
		b--;
	}
}
