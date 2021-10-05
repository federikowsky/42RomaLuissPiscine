/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:25:45 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/04 19:35:07 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	plusminus(char *s, int *conta) {
  int	i;
  int 	plus;
  int 	minus;
  
 	i = 0;
 	plus = 0;
 	minus = 0;
 	while (s[i] <= 48 || s[i] >= 57) 
	{
	if (s[i] == 43)
		plus++;
	else if(s[i] == 45)
		minus++;
	i++;
	}
	*conta = i;
	if ( plus < minus)
		return ('-');
	else
		return ('+');
}

int	ft_atoi(char *str)
{
	int		i;
	char	c;
	int		j;
  
	i = 0;
	c = plusminus(s,&j);
	while (s[j] >= 48 && s[j] <= 57)
	{
		i *= 10;
    	i += s[j] - 48;
    	j++;
	}
	if (c == '-')
		i *= -1;
	return (i);
}
