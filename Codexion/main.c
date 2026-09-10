#include "incs/codexion.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char **args;
	if (argc != 8)
	{
		fprintf(stderr, "Usage: %s <args>", argv[0]);
		return (-1);
	}
	args = parser(argc, argv);
	return (0);
}

