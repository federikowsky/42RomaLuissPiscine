/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:45:40 by fgrossi           #+#    #+#             */
/*   Updated: 2021/10/12 17:34:51 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

void	ft_str_sort(char **arr, int size, int offset)
{
	int		i;
	bool	check;

	i = offset;
	while (true)
	{
		i = offset;
		check = false;
		while (i < size)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				ft_swap(&arr[i], &arr[i + 1]);
				check = true;
			}
			i++;
		}
		if (!check)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 2)
		ft_str_sort(argv, argc - 1, 1);
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
}
