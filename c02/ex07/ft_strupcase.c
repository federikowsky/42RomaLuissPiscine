/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:19:53 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/01 10:51:44 by fefilipp         ###   ########.fr       */
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

char	*ft_strupcase(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len(str);
	while (i < len)
	{
		if ('z' >= str[i] && 'a' <= str[i])
			str[i] -= 32;
		i++;
	}
}
