/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hardcode.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:15 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/12/05 10:35:19 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	hardcode(int argc, t_push *stack)
{
	if (is_sorted(stack) == 0)
		exit (0);
	if (argc == 2)
		hc_two(stack);
	if (argc == 3)
		hc_three(stack);
	if (argc == 4)
		hc_four(stack);
	if (argc == 5)
		hc_five(stack);
}

void	hc_two(t_push	*stack)
{
	if (stack->a[0].num > stack->a[1].num)
		rotatea(stack);
}

void	hc_three(t_push	*stack)
{
	if (stack->a[0].num > stack->a[1].num
		&& stack->a[1].num > stack->a[2].num)
	{
		rotatea(stack);
		swapa(stack);
	}
	if (stack->a[1].num > stack->a[2].num
		&& stack->a[2].num > stack->a[0].num)
	{
		pushtob(stack);
		hc_two(stack);
		pushtoa(stack);
	}
	else if (stack->a[2].num > stack->a[0].num
		&& stack->a[0].num > stack->a[1].num)
		swapa(stack);
	else if (stack->a[1].num > stack->a[0].num
		&& stack->a[0].num > stack->a[2].num)
		reverse_rotate_a(stack);
	else if (stack->a[0].num > stack->a[2].num
		&& stack->a[2].num > stack->a[1].num)
		rotatea(stack);
	if (stack->a[0].num > stack->a[1].num)
		swapa(stack);
}

void	hc_four(t_push *stack)
{
	int	min_pos;

	min_pos = smallest(stack);
	if (min_pos == 1)
		swapa(stack);
	if (min_pos == 2)
	{
		rotatea(stack);
		rotatea(stack);
	}
	if (min_pos == 3)
		reverse_rotate_a(stack);
	pushtob(stack);
	hc_three(stack);
	pushtoa(stack);
}

void	hc_five(t_push *stack)
{
	int	min_pos;

	min_pos = smallest(stack);
	if (min_pos == 1)
		swapa(stack);
	if (min_pos == 2)
	{
		rotatea(stack);
		rotatea(stack);
	}
	if (min_pos == 3)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	if (min_pos == 4)
		reverse_rotate_a(stack);
	pushtob(stack);
	hc_four(stack);
	pushtoa(stack);
	if (stack->a[0].num > stack->a[1].num)
		swapa(stack);
}
