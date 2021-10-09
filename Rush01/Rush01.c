/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:55:32 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/09 17:31:07 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
//#include <stdio.h>
#include "rush.h"

int	**alloca_matrix(int riga, int colonna)
{
	int	i;
	int	**mat;

	mat = (int **)malloc(sizeof(int *) * riga);
	i = 0;
	while (i < riga)
	{
		mat[i] = (int *)malloc(sizeof(int) * colonna);
		i++;
	}
	return (mat);
}

int len(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + len(s + 1));
}

int	check_string(char *s)
{
	int	i;

	if (len(s) != 31 && len(s) != 16)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!(s[i] > '0' && s[i] < '5') && s[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
