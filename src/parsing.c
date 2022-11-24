/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 23:00:00 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/11/24 02:35:01 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_push *stack, int argc, char **numbers)
{
	int	i;

	i = 0;
	stack->a = ft_calloc((argc + 1), sizeof(t_stacks));
	if (!stack->a)
		return ;
	stack->b = ft_calloc((argc + 1), sizeof(t_stacks));
	if (!stack->b)
		return ;
	while (i < argc)
	{
		stack->a[i].num = ft_atoi(numbers[i]);
		stack->a[i].old_pos = i;
		stack->a[i].original = stack->a[i].num;
		i++;
	}
	stack->alen = i;
	stack->blen = 0;
	stack->maxnum = 0;
	stack->maxbits = 0;
}

int	parse(char	**argv, int argc, t_push *stack)
{
	char	**numbers;
	int		i;

	i = 0;
	if (argc == 1)
	{
		write(2, "Invalid amount of arguements\n", 30);
		return (-1);
	}
	else
		numbers = ft_split(argv[1], ' ');
	argc = 0;
	while (numbers[argc])
		argc++;
	if (argc < 1)
	{
		write(2, "Invalid amount of arguements\n", 30);
		return (-1);
	}
	init(stack, argc, numbers);
	return (argc);
}