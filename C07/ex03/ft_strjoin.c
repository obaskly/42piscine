/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:12:28 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/25 13:46:18 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_len_calculation(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_len(strs[i]);
		i++;
	}
	total_len += ft_len(sep) * (size - 1) + 1;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ara;
	int		total_len;
	int		i;

	if (size == 0)
	{
		ara = (char *)malloc(sizeof(char));
		*ara = '\0';
		return (ara);
	}
	total_len = total_len_calculation(size, strs, sep);
	ara = (char *)malloc(sizeof(char) * total_len);
	if (!ara)
		return (NULL);
	i = 0;
	ara[0] = '\0';
	while (i < size)
	{
		ft_strcat(ara, strs[i]);
		if (i < size - 1)
			ft_strcat(ara, sep);
		i++;
	}
	return (ara);
}
