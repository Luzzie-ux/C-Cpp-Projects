/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:35:34 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 14:40:54 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	words(const char *s, char d)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == d || s[i + 1] == 0)
			count++;
		i++;
	}
	return (count);
}

static int	alloc(char **res, const char *start, char d)
{
	int		i;

	i = 0;
	while (start[i] != d && start[i] != '\0')
		i++;
	*res = malloc((start[0] - start[i]) + 1);
	if (!*res)
		return (1);
	return (0);
}

static void	*set_buf(char **res, const char *s, int words, char d)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = 0;
	while (++j < words)
	{
		if (alloc(&res[j], &s[i], d))
			return (NULL);
		k = 0;
		while (s[i] != '\0' && s[i] != ' ')
			res[j][k++] = s[i++];
		res[j][k] = 0;
		i++;
	}
	res[j] = 0;
	return (res);
}

char	**split(const char *s, char c)
{
	size_t	n;
	char	**res;

	n = words(s, c);
	res = malloc(sizeof(char *) * (n + 1));
	if (!set_buf(&*res, s, n, c))
		return (NULL);
	return (res);
}
