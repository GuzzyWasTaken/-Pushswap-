/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 21:40:57 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/12/06 15:26:37 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push	stack;

	if (argc == 1)
		exit (0);
	if (argc <= 2)
		argc = parse(argv, argc, &stack);
	else
	{
		parse_strings(argc, argv, &stack);
		argc = argc -1;
	}
	bub(&stack);
	if (double_check (stack) == 1)
		ps_error("Error");
	buble_two (&stack);
	if (argc <= 5)
	{
		hardcode(argc, &stack);
		exit (0);
	}
	if (is_sorted(&stack) == 0)
		exit (0);
	radix(&stack);
	exit (0);
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

int	is_sorted(t_push *stack)
{
	int	i;

	i = 0;
	while (i < stack->alen - 1)
	{
		if (stack->a[i].num < stack->a[i + 1].num)
			i++;
		else
			return (1);
	}
	return (0);
}
