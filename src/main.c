/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 21:40:57 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/24 02:31:57 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push	stack;

	if (argc <= 2)
	{
		argc = parse(argv, argc, &stack);
		if (argc == -1)
			return (EXIT_FAILURE);
	}
	else
		fillstack(&stack, argc, argv);
	bub(&stack);
	if (double_check (stack) == 1)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	buble_two (&stack);
	if (argc <= 5)
	{
		hardcode(argc, &stack);
		return (0);
	}
	radix(&stack);
}

int	smallest(t_push *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->a[0].original;
	while (stack->a[i].original)
	{
		if (min > stack->a[i].original)
			min = stack->a[i].original;
		i++;
	}
	i = 0;
	while (stack->a[i].original != min)
		i++;
	return (i);
}
