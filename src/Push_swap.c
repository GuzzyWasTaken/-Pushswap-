/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:22 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/16 18:14:02 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	get_max_bit(t_push	*stack)
{
	int	i;

	i = 0;
	while (i < stack->alen)
	{
		if (stack->a[i].num > stack->maxnum)
			stack->maxnum = stack->a[i].num;
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
	int			j;

	i = -1;
	j = 1;
	while (j)
	{
		i = -1;
		j = 0;
		while (++i < stack->alen - 1)
		{
			if (stack->a[i].old_pos > stack->a[i + 1].old_pos)
			{
				tmp = stack->a[i + 1];
				stack->a[i + 1] = stack->a[i];
				stack->a[i] = tmp;
				j++;
			}
		}
	}
	get_max_bit(stack);
}

void	bub(t_push *stack)
{
	int			i;
	int			j;
	t_stacks	tmp;

	j = 1;
	i = -1;
	while (j != 0)
	{
		i = -1;
		j = 0;
		while (++i < stack->alen - 1)
		{
			if (stack->a[i].num > stack->a[i + 1].num)
			{
				tmp = stack->a[i + 1];
				stack->a[i + 1] = stack->a[i];
				stack->a[i] = tmp;
				j++;
			}
		}
	}
	i++;
	while (--i >= 0)
		stack->a[i].num = i;
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
			if (((stack->a[0].num >> x) & 1) == 0)
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
