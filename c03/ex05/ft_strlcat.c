/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:48:28 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/04 11:50:57 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char*s)
{
	if (*s == '\0')
		return (0);
	return (1 + len(s + 1));
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*d;
	char			*s;
	unsigned int	dest_lungh;
	unsigned int	conta;

	d = dest;
	s = src;
	conta = size;
	while (*d != '\0' && conta-- != 0)
		d++;
	dest_lungh = d - dest;
	if (conta == 0)
		return (dest_lungh + len(src));
	while (*s != '\0')
	{
		if (conta != 0)
		{
			*d++ = *s;
			conta--;
		}
		s++;
	}
	*d = '\0';
	return (dest_lungh + (s - src));
}
