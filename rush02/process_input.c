#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"

void	fill_SCL(PointSCL scl, char *s)
{
	if (*s == '\0')
		return ;
	node_alloc(&scl, s);
}

t_ull	ft_atoi(const char *S)
{
	unsigned long long	num;

	num = 0;
	while (*S && (*S >= '0' && *S <= '9'))
	{
		num = num * 10 + (*S - '0');
		S++;
	}
	return (num);
}

t_ull	ft_len(char *s)
{
	if (*s == '\n')
		return (0);
	if (*s == '{')
		return (0);
	return (1 + ft_len(s + 1));
}

char	*get_string(char *s)
{
	char	*ris;
	int		i;
	int		count;

	i = -1;
    count = 0;
	while (!(*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122))
		s++;
	while (s[++i] != '\n')
	{
		if ((s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123))
			count++;
	}
	ris = (char *)malloc(sizeof(char) * count);
	i = 0;
	while (*s != '\n')
	{
		if ((*s > 64 && *s < 91) || (*s > 96 && *s < 123))
			ris[i++] = *s++;
	}
	ris[i] = '\0';
	return (ris);
}


