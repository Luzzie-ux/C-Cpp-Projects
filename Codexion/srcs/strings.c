#include "../incs/codexion.h"

size_t 	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while(s1[i] == s2[i] && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

long ft_atol(const char *nptr)
{
	long	res;
	char 	*ptr;

	res = 0;
	ptr = (char*)nptr;
	if (*ptr == '+')
		ptr++;
	while(*ptr >= '0' && *ptr <= '9')
	{
		res *= 10 + (*ptr - '0');
		ptr++;
	}
	return (res);
}
