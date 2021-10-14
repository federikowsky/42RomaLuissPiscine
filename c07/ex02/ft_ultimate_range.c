/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:00:07 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/14 09:21:58 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	range = (int**)malloc(sizeof(int *));
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (range == 0)
		return (-1);
	i = 0;
	while (i < max - min)
		*range[i++] = min + i;
	return (i);
}
