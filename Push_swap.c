/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:22 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/10/06 19:39:57 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	get_max_bit(t_push	*stack)
{
	int	i;

	i = 0;
	while (i < stack->alen)
	{
		if (stack->bucket[i].stack > stack->maxnum)
			stack->maxnum = stack->bucket[i].stack;
		i++;
	}
	while (stack->maxnum >> stack->maxbits != 0)
	{
		stack->maxbits++;
	}
}

void	buble_two(t_push *stack)
{	
	int			i;
	t_stacks	tmp;
	int			swamp;

	i = -1;
	swamp = 1;
	while (swamp)
	{
		i = -1;
		swamp = 0;
		while (++i < stack->alen - 1)
		{
			if (stack->bucket[i].old_pos > stack->bucket[i + 1].old_pos)
			{
				tmp = stack->bucket[i + 1];
				stack->bucket[i + 1] = stack->bucket[i];
				stack->bucket[i] = tmp;
				swamp++;
			}
		}
	}
	get_max_bit(stack);
}

void	bub(t_push *stack)
{
	int			i;
	int			swamp;
	t_stacks	tmp;

	swamp = 1;
	i = -1;
	while (swamp != 0)
	{
		i = -1;
		swamp = 0;
		while (++i < stack->alen - 1)
		{
			if (stack->bucket[i].stack > stack->bucket[i + 1].stack)
			{
				tmp = stack->bucket[i + 1];
				stack->bucket[i + 1] = stack->bucket[i];
				stack->bucket[i] = tmp;
				swamp++;
			}
		}
	}
	i++;
	while (--i >= 0)
		stack->bucket[i].stack = i;
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	radix(t_push *stack)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (++x < stack->maxbits)
	{
		i = 0;
		while (i < stack->alen)
		{
			if (((stack->bucket[0].stack >> x) & 1) == 0)
			{
				pushtob(stack);
				i--;
			}
			rotatea(stack);
			i++;
		}
		while (stack->blen > 0)
		{
			pushtoa (stack);
		}
	}
}
