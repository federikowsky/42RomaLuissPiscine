/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:29:08 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/05 21:46:39 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_len(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + ft_len(s + 1));
}

int	valid_base(char *str)
{
	char	*curr;
	int		index;
	int		jndex;

	curr = str;
	if (str == 0 || ft_len(str) <= 1)
		return (0);
	while (*curr)
	{
		if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f'
			|| *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
			return (0);
		curr++;
	}
	index = 0;
	while (index < curr - str)
	{
		jndex = index + 1;
		while (jndex < curr - str)
			if (str[index] == str[jndex++])
				return (0);
		index++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenght;

	lenght = ft_len(base);
	if (!valid_base(base))
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / lenght, base);
		write(1, &(base[-(nbr % lenght)]), 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	if (nbr > 0)
	{
		ft_putnbr_base(nbr / lenght, base);
		write(1, &base[nbr % lenght], 1);
	}
}
