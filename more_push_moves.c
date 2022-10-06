#include "push_swap.h"

void	swaptopb(t_push *stack)
{
	t_stacks	tmp;

	tmp = stack->bucketb[0];
	stack->bucketb[0] = stack->bucketb[stack->blen];
	stack->bucketb[stack->blen] = tmp;
}

void	rotatea(t_push *stack)
{
	t_stacks	tmp;
	int			i;

	i = -1;
	tmp = stack->bucket[0];
	while (++i < stack->alen)
		stack->bucket[i] = stack->bucket[i + 1];
	stack->bucket[stack->alen - 1] = tmp;
	write(1, "ra", 2);
	write(1, "\n", 1);
}


void	rotateb(t_push *stack)
{
	t_stacks	tmp;
	int			i;

	i = -1;
	tmp = stack->bucketb[0];
	while (++i < stack->blen)
		stack->bucket[i] = stack->bucket[i + 1];
	stack->bucket[i] = tmp;
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	reverse_rotate_a(t_push *stack)
{
	t_stacks	tmp;
	int			i;

	i = stack->alen;
	tmp = stack->bucket[stack->alen - 1];
	while (--i > 0)
		stack->bucket[i] = stack->bucket[i - 1];
	stack->bucket[0] = tmp;
	write(1, "rra", 2);
	write(1, "\n", 1);
}