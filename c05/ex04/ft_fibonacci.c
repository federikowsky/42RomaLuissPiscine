/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:17:18 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/13 14:09:08 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci_recursive(int value, int n1, int n2)
{
	int	n0;

	if (value < 1)
		return (n1 + n2);
	n0 = n2;
	n2 = n1 + n2;
	n1 = n0;
	return (ft_fibonacci_recursive(value - 1, n1, n2));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	return (ft_fibonacci_recursive(index - 2, 0, 1));
}
