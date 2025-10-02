/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:38:03 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/22 13:09:43 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ara;

	if (min >= max)
	{
		*range = (NULL);
		return (0);
	}
	ara = (int *)malloc(sizeof(int) * (max - min));
	if (!ara)
		return (-1);
	i = 0;
	while (min < max)
	{
		ara[i] = min;
		min++;
		i++;
	}
	*range = ara;
	return (i);
}
