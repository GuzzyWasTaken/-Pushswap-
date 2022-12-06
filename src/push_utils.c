/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 15:19:10 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/12/06 15:19:56 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	min_max(unsigned long num, int sign)
{
	if (sign == -1 && num == 2147483648)
		return (-2147483648);
	if (num > 2147483647)
	{
		write (1, "Error\n", 6);
		exit (1);
	}
	return (0);
}

int	ft_atoi(const char	*s)
{
	int				i;
	unsigned long	num;

	i = 1;
	num = 0;
	while (*s == '\n' || *s == '\t' || *s == '\r' || *s == '\n'
		|| *s == '\v' || *s == '\f' || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			i = -1;
		s++;
	}
	while ((*s >= '0') && (*s <= '9'))
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	min_max (num, i);
	return ((int)num * i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int			*p;
	size_t		i;

	i = -1;
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	while (++i < size)
		p[i] = '\0';
	return (p);
}

void	fillstack(t_push *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	stack->a = ft_calloc((argc + 1), sizeof(t_stacks));
	if (!stack->a)
		exit (1);
	stack->b = ft_calloc((argc + 1), sizeof(t_stacks));
	if (!stack->b)
		exit (1);
	while (++i < argc)
	{
		printf("in while\n");
		stack->a[i - 1].num = ft_atoi(argv[i]);
		stack->a[i - 1].old_pos = i - 1;
		stack->a[i - 1].original = stack->a[i - 1].num;
	}
	stack->alen = i - 1;
	stack->blen = 0;
	stack->maxnum = 0;
	stack->maxbits = 0;
}

int	double_check(t_push stack)
{
	int	i;

	i = -1;
	while (++i < stack.alen - 1)
		if (stack.a[i].original == stack.a[i + 1].original)
			return (1);
	return (0);
}
