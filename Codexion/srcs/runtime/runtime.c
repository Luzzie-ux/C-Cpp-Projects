/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:10:46 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 19:18:16 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

_Bool	tcreate(t_coder *coder)
{
	if (pthread_create(&coder->thread, NULL, compile, coder))
		return (true);
	coder->right->is_taken = false;
	coder->right->is_taken = false;
	return (false);
}

_Bool	tclose(t_coder *coder)
{ 
	if (pthread_join(coder->thread, NULL))
		return (true);
	return (false);
}

_Bool	get_dongle(t_coder *coder)
{
	if (coder->right->is_taken || coder->left->is_taken)
		return (true);
	coder->right->is_taken = true;
	coder->left->is_taken = true;
	printf("%ld has taken a dongle\n", coder->id);
	printf("%ld has taken a dongle\n", coder->id);
	return (false);
}

_Bool	threads(t_table *table)
{
	size_t i;
	t_coder *coders;

	i = 0;
	coders = table->coders;
	while(i <= table->elements)
	{
		if (get_dongle(&coders[i]))
		{
			i++;
			continue ;
		}
		else if (tcreate(&coders[i]))
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
	while (i <= table->nbr_compiles)
	{
		if (threads(table))
			return (kill(table), true);
		printf("end of compilation %ld\n\n", i);
		i++;
	}
	return (false);
}
