#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	push_swap(argc, argv);
	return (0);
}
