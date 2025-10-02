/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:21:00 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/22 13:00:09 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ara;

	if (min >= max)
		return (NULL);
	ara = (int *)malloc(sizeof(int) * (max - min));
	if (!ara)
		return (NULL);
	i = 0;
	while (min < max)
	{
		ara[i] = min;
		min++;
		i++;
	}
	return (ara);
}
