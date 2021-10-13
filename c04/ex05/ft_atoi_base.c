/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:44:59 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/12 22:48:00 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + ft_strlen(str + 1));
}

bool	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

bool	is_base_valid(char *str)
{
	char	*curr;
	int		i;
	int		j;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (false);
	while (*curr)
	{
		if (is_space(*curr) || *curr == '+' || *curr == '-')
			return (false);
		curr++;
	}
	i = 0;
	while (i < curr - str)
	{
		j = i + 1;
		while (j < curr - str)
			if (str[i] == str[j++])
				return (false);
		i++;
	}
	return (true);
}

int	resolve_base(char *base, char match, int i)
{
	if (base[i] == '\0')
		return (-1);
	if (base[i] == match)
		return (i);
	return (resolve_base(base, match, i + 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	lenght;
	int	result;
	int	minus;
	int	resolved;

	if (!is_base_valid(base))
		return (0);
	lenght = ft_strlen(base);
	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (resolve_base(base, *str, 0) != -1)
	{
		result *= lenght;
		result += resolve_base(base, *str, 0);
		str++;
	}
	return (result * minus);
}
