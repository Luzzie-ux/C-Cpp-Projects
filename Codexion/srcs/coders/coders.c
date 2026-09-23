/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:23:13 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 12:15:28 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*dongle(t_table *table)
{
	int	i;

	i = 0;
	table->dongles = malloc(sizeof(t_dongle) * table->elements);
	if (!table->dongles)
		return (NULL);
	while ((size_t)i < table->elements)
	{
		table->dongles[i].id = i;
		table->dongles[i].is_taken = false;
		table->dongles[i].cooldown = table->dongle_cooldown;
		i++;
	}
	return (table);
}

void	*coder(t_table *table)
{
	int	i;

	i = 0;
	table->coders = malloc(sizeof(t_coder) * table->elements);
	if (!table->coders)
		return (NULL);
	while ((size_t)i < table->elements)
	{
		table->coders[i].id = i + 1;
		table->coders[i].action = NONE;
		table->coders[i].compiles = 0;
		table->coders[i].left = &table->dongles[i];
		table->coders[i].right = &table->dongles[(i + 1) % 10];
		i++;
	}
	return (table);
}

int		table(t_table *table, char **argv)
{
	if (parser(&*table, argv))
		return (1);
	else if (!dongle(&*table))
		return (1);
	else if (!coder(&*table))
		return (free(table->dongles), 1);
	return (0);
}
