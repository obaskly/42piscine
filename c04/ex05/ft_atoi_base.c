/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochaouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:48:08 by mochaouc          #+#    #+#             */
/*   Updated: 2025/09/22 16:33:34 by mochaouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i])
	{
		if (c[i] == '+' || c[i] == '-' || c[i] == 32
			|| (c[i] >= 9 && c[i] <= 13))
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

int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_helper(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

int ft_atoi_base(char *str, char *base)
{
    int     i;
    int     base_len;
    int     sign;
    long    result;
    int     digit_value;

    base_len = check_base(base);
    if (base_len == 0)
        return (0);
    i = 0;
    result = 0;
    sign = ft_helper(str, &i);
    while (str[i])
    {
        digit_value = get_value(str[i], base);
        if (digit_value == -1)
            break ;
        result = (result * base_len) + digit_value;
        i++;
    }
    return ((int)(result * sign));
}
