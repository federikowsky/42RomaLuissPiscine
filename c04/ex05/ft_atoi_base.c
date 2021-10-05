/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:44:59 by fefilipp          #+#    #+#             */
/*   Updated: 2021/10/05 22:46:40 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define NO_MATCH -1

int        ft_strlen(char *str)
{
    int    index;

    index = 0;
    while (str[index])
        index++;
    return (index);
}

bool    is_space(char c)
{
    return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
        || c == '\r' || c == ' ');
}

bool    is_base_valid(char *str)
{
    char    *curr;
    int        index;
    int        jndex;

    curr = str;
    if (str == 0 || ft_strlen(str) <= 1)
        return (false);
    while (*curr)
    {
        if (is_space(*curr) || *curr == '+' || *curr == '-')
            return (false);
        curr++;
    }
    index = 0;
    while (index < curr - str)
    {
        jndex = index + 1;
        while (jndex < curr - str)
            if (str[index] == str[jndex++])
                return (false);
        index++;
    }
    return (true);
}

int        resolve_base(char *base, char match)
{
    int        index;

    index = 0;
    while (base[index])
    {
        if (base[index] == match)
            return (index);
        index++;
    }
    return (NO_MATCH);
}

int        ft_atoi_base(char *str, char *base)
{
    int    radix;
    int    result;
    int    minus;
    int    resolved;

    if (!is_base_valid(base))
        return (0);
    radix = ft_strlen(base);
    result = 0;
    minus = 1;
    while (is_space(*str))
        str++;
    while (*str == '+' || *str == '-')
    {
        if (*str == '-')
            minus *= -1;
        str++;
    }
    while ((resolved = resolve_base(base, *str)) != NO_MATCH)
    {
        result *= radix;
        result += resolved;
        str++;
    }
    return (result * minus);
}

int main() {
  char *base = "0123456789ABCDEF";
  char *s = "  --++-4536ciao";
  int x = ft_atoi_base(s,base);
  printf("%d",x);
  return 0;
}
