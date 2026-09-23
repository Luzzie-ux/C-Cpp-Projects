/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:10:46 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 20:45:41 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

_Bool	tcreate(t_coder *coder)
{
	if (pthread_create(&coder->thread, NULL, compile, coder))
		return (true);
	return (false);
}

_Bool	tclose(t_coder *coder)
{ 
	if (pthread_join(coder->thread, NULL))
		return (true);
	return (false);
}

_Bool	threads(t_table *table)
{
	size_t	i;
	t_coder *coders;

	i = 0;
	coders = table->coders;
	while(i < table->elements)
	{
		coders[i].get_dongle(&coders[i]);
		if (tcreate(&coders[i]))
			return (true);
		else if (tclose(&coders[i]))
			return (true);
		i++;
	}
	return (false);
}

_Bool	init(t_table *table)
{
	size_t i;

	i = 0;
	while (i < table->nbr_compiles)
	{
		if (threads(table))
			return (kill(table), true);
		printf("Check: [Task %ld completed]\n\n", i + 1);
		i++;
	}
	return (false);
}
