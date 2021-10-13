/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:25:45 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/13 14:12:20 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	plusminus(char *s, int *conta, int *minus)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	*minus = 1;
	while (s[i] <= 48 || s[i] >= 57)
	{
		if (s[i] == 45 || s[i] == 43)
		{
			if (s[i] == 45)
				*minus *= -1;
			valid = 0;
		}
		if ((s[i] != 45 && s[i] != 43) && valid == 0)
		{
			valid = 1;
			break ;
		}
		i++;
	}
	*conta = i;
	return (valid);
}

int	ft_atoi(char *str)
{
	int		i;
	int		minus;
	int		j;

	i = 0;
	if (plusminus(str, &j, &minus))
		return (0);
	while (str[j] >= 48 && str[j] <= 57)
	{
		i *= 10;
		i += str[j] - 48;
		j++;
	}
	return (i * minus);
}
