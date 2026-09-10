#include "../incs/codexion.h"

static int negatives(char *arg)
{
	size_t len;

	len = ft_strlen(arg);
	if (!len)
		return (1);
	
}
static int characters(char *arg);
static int scheduler(char *arg);

static int check(char **args)
{
	int	i;

	i = 1;
	if (scheduler(args[8]))
		return (1);
	while (i < 8)
	{
		if (negatives(args[i]))
			return (1);
		if (characters(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int parser(t_table *table, char **argv)
{
	if (check(argv))
		return (1);
	table->elements = ft_atoi(argv[1]);
	table->burnout = ft_atoi(argv[2]);
	table->compile = ft_atoi(argv[3]);
	table->debug = ft_atoi(argv[4]);
	table->refactor = ft_atoi(argv[5]);
	table->nbr_compiles = ft_atoi(argv[6]);
	table->dongle_cooldown = ft_atoi(argv[7]);
	table->schedule = ft_atoi(argv[8]);
	return (0);
}

/* ARGS:
./codexion 0
number_of_coders 1
time_to_burnout 2
time_to_compile 3
time_to_debug 4
time_to_refactor 5 
number_of_compiles_required 6
dongle_cooldown 7
scheduler 8
*/
