/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_moves.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:19 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/15 18:08:18 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swapa(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->bucket[0];
	stack->bucket[0] = stack->bucket[1];
	stack->bucket[1] = tmp;
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void	swapb(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->bucket[0];
	stack->bucket[0] = stack->bucket[1];
	stack->bucket[1] = tmp;
	write(1, "sb", 2);
	write(1, "\n", 1);
}

void	pushtoa(t_push *stack)
{
	int			i;

	i = stack->alen + 1;
	while (--i > 0)
		stack->bucket[i] = stack->bucket[i - 1];
	stack->bucket[0] = stack->bucketb[0];
	i = -1;
	while (++i < stack->blen)
		stack->bucketb[i] = stack->bucketb[i + 1];
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
		stack->bucketb[i] = stack->bucketb[i - 1];
	stack->bucketb[0] = stack->bucket[0];
	i = -1;
	while (++i < stack->alen)
		stack->bucket[i] = stack->bucket[i + 1];
	stack->blen = stack->blen + 1;
	stack->alen = stack->alen - 1;
	write(1, "pb", 2);
	write(1, "\n", 1);
}


void	swaptopa(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->bucket[0];
	stack->bucket[0] = stack->bucket[stack->alen];
	stack->bucket[stack->alen] = tmp;

}

