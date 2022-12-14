/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: auzochuk <auzochuk@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:13:26 by auzochuk      #+#    #+#                 */
/*   Updated: 2022/04/11 16:59:49 by auzochuk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	stack;
	int	old_pos;
	int	original;
}	t_stacks;

typedef struct s_push
{
	t_stacks	*bucket;
	t_stacks	*bucketb;
	int			alen;
	int			blen;
	int			maxnum;
	int			maxbits;
}	t_push;

void	rotateb(t_push *stack);
void	rotatea(t_push *stack);
void	swaptopb(t_push *stack);
void	swaptopa(t_push *stack);
void	pushtob(t_push *stack);
void	pushtoa(t_push *stack);
void	swapb(t_push *stack);
void	swapa(t_push *stack);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char	*s);
void	*ft_calloc(size_t nmemb, size_t size);
void	fillstack(t_push *stack, int argc, char **argv);
void	radix(t_push *stack);
void	get_max_bit(t_push	*stack);
void	bub(t_push *stack);
void	buble_two(t_push *stack);
int		double_check(t_push stack);
void	hardcode(int argc, t_push *stack);
void 	hc_two(t_push	*stack);
void 	hc_three(t_push	*stack);
void	hc_five(t_push	*stack);
void	reverse_rotate_a(t_push *stack);

#endif