/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 23:00:00 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/12/06 15:51:04 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

/**
checks for valid input on each argv string
*/
int	check_input(char **argv)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (argv[x])
	{
		i = 0;
		while (argv[x][i])
		{
			if (ft_isdigit(argv[x][i]) == false)
				if (argv[x][i] != '-' && argv[x][i] != '+')
					return (-1);
			if (argv[x][i] == '-' || argv[x][i] == '+')
				if (ft_isdigit(argv[x][i + 1]) == false)
					return (-1);
			if (argv[x][i + 1] && ft_isdigit(argv[x][i + 1]) == true)
				if (argv[x][i] == '-' || argv[x][i] == '+')
					if ((argv[x][i - 1]) && (argv[x][i] != ' '))
						return (-1);
			i++;
		}
		x++;
	}
	return (0);
}

void	ps_error(char *error_message)
{
	write (2, error_message, ft_strlen(error_message));
	write (2, "\n", 1);
	exit (1);
}

int	parse(char	**argv, int argc, t_push *stack)
{
	int		i;

	i = 0;
	if (argc == 1)
		ps_error("Error");
	if (i <= 2)
		exit (0);
	stack->numbers = ft_split(argv[1], ' ');
	argc = 0;
	while (stack->numbers[argc])
		argc++;
	if (argc < 1)
		ps_error("Error");
	if (check_input(stack->numbers) == -1)
		ps_error("Error");
	init(stack, argc, stack->numbers);
	return (argc);
}
