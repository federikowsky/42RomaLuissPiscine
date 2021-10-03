/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 22:26:23 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/03 17:09:27 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*d;

	if (*to_find == '\0')
		return (str);
	s = str;
	d = to_find;
	while (*s != '\0')
	{
		if (*d == '\0')
			return ((char *)(s - (d - to_find)));
		if (*s == *d)
			d++;
		else
			d = to_find;
		s++;
	}
	return (0);
}
