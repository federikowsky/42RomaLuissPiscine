/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:09:46 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/13 13:53:24 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_count;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_solve(char *tab, int x, int *max)
{
	int	i;
	int	j;

	if (x == 10)
	{
		x = 0;
		while (x < 10)
			ft_putchar(tab[x++] + '0');
		ft_putchar('\n');
		(*max)++;
		g_count++;
		return ;
	}
	i = -1;
	while (++i < 10)
	{
		j = 0;
		while (j < x && i != tab[j] && ft_abs(tab[j] - i) != x - j)
			j++;
		if (j >= x)
		{
			tab[x] = i;
			ft_solve(tab, x + 1, max);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[10];
	int		max;
	int		result;

	max = 0;
	ft_solve(tab, 0, &max);
	result = g_count;
	g_count = 0;
	return (max);
}
