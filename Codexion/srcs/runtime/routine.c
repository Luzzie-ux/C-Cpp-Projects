/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:32:30 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 20:41:59 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*compile(void *coder)
{
	t_coder *cd;

	cd = (t_coder *)coder;
	printf("%ld is compiling\n", cd->id);
	debug(coder);
	return (NULL);
}

void	*debug(void *coder)
{
	t_coder *cd;

	cd = (t_coder *)coder;
	printf("%ld is debugging\n", cd->id);
	refactor(coder);
	return (NULL);
}

void	*refactor(void *coder)
{
	t_coder *cd;

	cd = (t_coder *)coder;
	printf("%ld is refactoring\n", cd->id);
	return (NULL);
}

