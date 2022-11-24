/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_moves.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:19 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/23 19:51:34 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swapa(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void	swapb(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	write(1, "sb", 2);
	write(1, "\n", 1);
}

void	pushtoa(t_push *stack)
{
	int			i;

	i = stack->alen + 1;
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = stack->b[0];
	i = -1;
	while (++i < stack->blen)
		stack->b[i] = stack->b[i + 1];
	stack->blen = stack->blen - 1;
	stack->alen = stack->alen + 1;
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	pushtob(t_push *stack)
{
	int			i;

	i = stack->blen + 1;
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = stack->a[0];
	i = -1;
	while (++i < stack->alen)
		stack->a[i] = stack->a[i + 1];
	stack->blen = stack->blen + 1;
	stack->alen = stack->alen - 1;
	write(1, "pb", 2);
	write(1, "\n", 1);
}

void	swaptopa(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[stack->alen];
	stack->a[stack->alen] = tmp;
}
