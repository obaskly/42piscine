/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:52:57 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/23 13:55:13 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *c)
{
	unsigned int	i;

	i = 0;
	while (*c)
	{
		c++;
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_len(src));
}
