/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:22:03 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/10 23:05:23 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/codexion.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 9)
		return (fprintf(stderr, "Usage: %s", argv[0]), usage());
	if (parser(&table, argv))
		return (1);
	printf("Everything Working :D !\n");
	return (0);
}
