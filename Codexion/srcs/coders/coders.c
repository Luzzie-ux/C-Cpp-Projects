/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:23:13 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 20:48:29 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

_Bool	get_dongle(t_coder *self)
{
	printf("Coder %ld has taken a dongle\n", self->id);
	printf("Coder %ld has taken a dongle\n", self->id);
	return (false);
}

_Bool	dongle(t_table *table)
{
	int	i;

	i = 0;
	table->dongles = malloc(sizeof(t_dongle) * table->elements);
	if (!table->dongles)
		return (true);
	while ((size_t)i < table->elements)
	{
		table->dongles[i].id = i;
		table->dongles[i].is_taken = false;
		table->dongles[i].cooldown = table->dongle_cooldown;
		i++;
	}
	return (false);
}

_Bool	coder(t_table *table)
{
	int	i;

	i = 0;
	table->coders = malloc(sizeof(t_coder) * table->elements);
	if (!table->coders)
		return (true);
	while ((size_t)i < table->elements)
	{
		table->coders[i].id = i + 1;
		table->coders[i].action = NONE;
		table->coders[i].compiles = 0;
		table->coders[i].left = &table->dongles[i];
		table->coders[i].right = &table->dongles[(i + 1) % 10];
		table->coders[i].burnout = table->burnout;
		table->coders[i].get_dongle = &get_dongle;
		i++;
	}
	return (false);
}

_Bool	table(t_table *table, char **argv)
{
	if (parser(table, argv))
		return (true);
	else if (dongle(table))
		return (true);
	else if (coder(table))
		return (free(table->dongles), 1);
	return (false);
}
