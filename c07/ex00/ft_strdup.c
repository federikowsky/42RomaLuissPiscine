/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:08:14 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/14 09:22:15 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	if (dest != 0)
		*dest = '\0';
	return (temp);
}

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + ft_strlen(str + 1));
}

char	*ft_strdup(char *src)
{
	char	*ris;

	ris = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (ris == 0)
		return (NULL);
	ris = ft_strcpy(ris, src);
	return (ris);
}
