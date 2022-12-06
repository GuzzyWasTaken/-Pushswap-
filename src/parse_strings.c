/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_strings.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 15:23:30 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/12/06 15:27:53 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_isdigit(char a)
{
	if ((a >= '0') && (a <= '9'))
		return (true);
	else
		return (false);
}

int	check_str(char	*str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) == 1 || str[i] == '-' || \
		str[i] == '+' || str[i] == ' '))
			return (1);
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i - 1] && str[i - 1] != ' ')
				return (1);
			if (str[i + 1] && ft_isdigit(str[i + 1]) == false)
				return (1);
			if ((str[i] == '+' || str[i] == '-') && (!str[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	parse_strings(int argc, char **argv, t_push *stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_str(argv[i]) == 1)
			ps_error("Error");
		i++;
	}
	printf("good input\n");
	fillstack(stack, argc, argv);
	return (0);
}