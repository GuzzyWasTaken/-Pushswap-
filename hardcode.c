/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hardcode.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:15 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/04/11 17:08:03 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	hardcode(int argc, t_push *stack)
{
	if (argc == 3)
		hc_two(stack);
	if (argc == 4)
		hc_three(stack);
	if (argc > 4)
		hc_five(stack);
}

void	hc_two(t_push	*stack)
{
	if (stack->bucket[0].stack > stack->bucket[1].stack)
		rotatea(stack);
}

void	hc_three(t_push	*stack)
{
	if (stack->bucket[0].stack > stack->bucket[1].stack
		&& stack->bucket[1].stack > stack->bucket[2].stack)
		swapa(stack);
	if (stack->bucket[1].stack > stack->bucket[2].stack
		&& stack->bucket[2].stack > stack->bucket[0].stack)
		reverse_rotate_a(stack);
	else if (stack->bucket[2].stack > stack->bucket[0].stack
		&& stack->bucket[0].stack > stack->bucket[1].stack)
		swapa(stack);
	else if (stack->bucket[1].stack > stack->bucket[0].stack
		&& stack->bucket[0].stack > stack->bucket[2].stack)
		reverse_rotate_a(stack);
	else if (stack->bucket[0].stack > stack->bucket[2].stack
		&& stack->bucket[2].stack > stack->bucket[1].stack)
		rotatea(stack);
	if (stack->bucket[0].stack > stack->bucket[1].stack)
		swapa(stack);
}

void	hc_five(t_push *stack)
{
	while (stack->alen > 3)
	{
		if (stack->bucket[0].stack == 0 || stack->bucket[0].stack == 1)
			pushtob(stack);
		else
			rotatea (stack);
	}
	hc_three(stack);
	while (stack->blen > 0)
		pushtoa(stack);
	if (stack->bucket[0].stack > stack->bucket[1].stack)
		swapa(stack);
}
