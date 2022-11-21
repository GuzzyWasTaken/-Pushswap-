/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hardcode.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:15 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/16 18:14:02 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	hardcode(int argc, t_push *stack)
{
	printf("in hc\n");
	if (argc == 3)
		hc_two(stack);
	if (argc == 4)
		hc_three(stack);
	if (argc == 6)
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

// void hc_four(t_push *stack)
// {
// 	while(i )
// 	if (stack->a[0].num > stack->a[1].num)
// }

void	hc_five(t_push *stack)
{
	
	
}

