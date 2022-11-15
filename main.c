#include "push_swap.h"
#include <stdio.h>

int	main(int argc ,char **argv)
{
	t_push	stack;

	setbuf(stdout, NULL);
	if (argc < 2)
		return (0);
	fillstack(&stack, argc, argv);
	bub(&stack);
	if (double_check (stack) == 1)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	buble_two (&stack);
	if (argc <= 6)
	{
		hardcode(argc, &stack);
		// while(++i < stack.alen)
		return (0);
	}
	radix(&stack);
}
