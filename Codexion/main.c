#include "incs/codexion.h"

int main(int argc, char **argv)
{
	t_table	table;
	if (argc != 9)
	{
		fprintf(stderr, "Usage: %s <nbr_of_coders> <time_burnout>", argv[0]);
		fprintf(stderr, " <time_compile> <time_debug> <time_refactor>");
		fprintf(stderr, " <nbr_of_compiles_required> <dongle_cooldown>");
		fprintf(stderr, " <scheduler>\n");
		return (1);
	}
	if (parser(&table, argv))
		return(1);
	printf("Everything Working :D !\n");
	return (0);
}

