/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_push_moves.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 21:41:07 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/23 21:46:04 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swaptopb(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[stack->blen];
	stack->b[stack->blen] = tmp;
}

void	rotatea(t_push *stack)
{
	t_stacks	tmp;
	int			i;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->alen)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->alen - 1] = tmp;
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rotateb(t_push *stack)
{
	t_stacks	tmp;
	int			i;

	i = -1;
	tmp = stack->b[0];
	while (++i < stack->blen)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	reverse_rotate_a(t_push *stack)
{
	t_stacks	tmp;
	int			i;

	i = stack->alen;
	tmp = stack->a[stack->alen - 1];
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = tmp;
	write(1, "rra", 3);
	write(1, "\n", 1);
}
