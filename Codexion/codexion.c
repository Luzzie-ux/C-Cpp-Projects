/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@42.student.porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 21:22:03 by rodrpere          #+#    #+#             */
/*   Updated: 2026/09/23 12:17:11 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_table	env;

	if (argc != 9)
		return (fprintf(stderr, "Usage: %s", argv[0]), usage());
	if (table(&env, argv))
		return (fprintf(stdin, "something went wrong\n"), 1);
	printf("Everything Working :D !\n");
	return (kill(&env), 0);
}
