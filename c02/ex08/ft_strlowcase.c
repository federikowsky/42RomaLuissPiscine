/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:52:45 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/01 10:53:30 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_len(char*s)
{
	int	conta;

	conta = 0;
	while (*s != '\0')
	{
		conta++;
		s++;
	}
	return (conta);
}

char	*ft_lowcase(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len(str);
	while (i < len)
	{
		if ('Z' >= str[i] && 'A' <= str[i])
			str[i] += 32;
		i++;
	}
}
