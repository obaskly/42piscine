/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:44:28 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/23 21:24:42 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *c)
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	original_dest;
	unsigned int	original_src;

	original_dest = ft_len(dest);
	original_src = ft_len(src);
	j = 0;
	if (original_dest >= size)
		return (original_src + size);
	while (j < (size - original_dest - 1) && src[j])
	{
		dest[original_dest + j] = src[j];
		j++;
	}
	dest[original_dest + j] = '\0';
	return (original_dest + original_src);
}
