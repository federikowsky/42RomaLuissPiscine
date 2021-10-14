/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:20:43 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/14 09:21:49 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *ris;
	int i;

	if (min >= max)
		return (NULL);
	ris = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
		ris[i++] = min + i;
	return (ris);
}
