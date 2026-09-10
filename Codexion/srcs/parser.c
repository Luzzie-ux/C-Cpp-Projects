#include "../incs/codexion.h"

static int characters(char *arg)
{
	size_t	i;

	i = 0;
	if (arg[i] == '-')
	{
		fprintf(stderr, "ERROR: Negative Integer -> %s\n", arg);
		return (1);
	}
	else if (arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "ERROR: Non-Intgeger -> %s\n", arg);
			return (1);
		}
		i++;
	}
	return (0);
}

static int scheduler(char *arg)
{
	if (*arg == '\0')
	{
		fprintf(stderr, "ERROR: Empty Schedule Argument\n");
		return (1);
	}
	if (ft_strcmp(arg, "fifo") || ft_strcmp(arg, "edf"))
	{
		fprintf(stderr, "ERROR: Not FIFO/EDF -> %s\n", arg);
		return (1);
	}
	return (0);
}

static int check(char **args)
{
	int	i;

	i = 0;
	if (scheduler(args[8]))
		return (1);
	while (++i < 8)
	{
		if (*args[i] == '\0' || !args[i] || !args)
		{
			fprintf(stderr, "ERROR: Empty Argument -> %s[%d]\n", args[i], i);
			return (1);
		}
		else if (characters(args[i]))
			return (1);
	}
	return (0);
}

int parser(t_table *table, char **argv)
{
	if (check(argv))
		return (1);
	table->elements = ft_atol(argv[1]);
	table->burnout = ft_atol(argv[2]);
	table->compile = ft_atol(argv[3]);
	table->debug = ft_atol(argv[4]);
	table->refactor = ft_atol(argv[5]);
	table->nbr_compiles = ft_atol(argv[6]);
	table->dongle_cooldown = ft_atol(argv[7]);
	table->schedule = ft_atol(argv[8]);
	return (0);
}

