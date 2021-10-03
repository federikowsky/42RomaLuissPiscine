/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:54:43 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/01 19:57:04 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_len(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + ft_len(s + 1));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	len;
	int	first;

	i = 0;
	first = 1;
	while (i < ft_len(str))
	{
		if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90 ))
		{
			if (first)
			{
				str[i] -= 32;
				first = 0;
			}
			else if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
		}		
		else if (str[i] <= 48 || str[i] >= 57)
			first = 1;
		else if (str[i] >= 48 && str[i] <= 57)
			first = 0;
		i++;
	}
	return (str);
}
