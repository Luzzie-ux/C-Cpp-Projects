/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:23:13 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/17 19:33:17 by rodrpere         ###   ########.fr       */
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
		table->dongles[i].is_taken = 0;
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
		table->coders[i].id = i;
		table->coders[i].action = NONE;
		table->coders[i].compiles = 0;
		table->coders[i].left = &table->dongles[i];
		table->coders[i].right = &table->dongles[(i + 1) % 10];
		i++;
	}
	return (table);
}
