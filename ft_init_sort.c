/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/14 16:16:27 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

void	ft_push_all(t_stack *sa, t_stack *sb, int div)
{
	int	i;
	int	p;

	i = 0;
	p = sa->max_size / div;
	while (p < sa->max_size)
	{
		i = 0;
		while (i < sa->max_size / div)
		{
			if (sa->tab[sa->size - 1] < p)
			{
				push_b(sa, sb);
				i++;
			}
			else
				rotate(sa, 'a');
			if (sb->tab[sb->size - 1] > (p - (sa->max_size / (div + div))))
				rotate(sb, 'b');
		}
		p += sa->max_size / div;
	}
}

void	ft_sort_more(t_stack *sa, t_stack *sb)
{
	int	i;

	i = 1;
	if (sa->max_size < 450)
		ft_push_all(sa, sb, 3);
	if (sa->max_size > 450)
		ft_push_all(sa, sb, 9);
	while (sa->size != 0)
		push_b(sa, sb);
	while (sb->size != 0)
	{
		ft_smart_rotate_sb(sb, sa->max_size - i);
		push_a(sa, sb);
		i++;
	}
}

void	ft_init_sort(t_stack *sa, t_stack *sb)
{
	if (sa->size == 1)
		return ;
	if (sa->size == 2)
		if (sa->tab[0] < sa->tab[1])
			swap(sa, 'a'); 
	if (sa->size == 3 && ft_stack_is_sorted(sa) == 0)
		ft_sort_three(sa);
	if ((sa->size == 4 || sa->size == 5) && ft_stack_is_sorted(sa) == 0)
		ft_sort_five(sa, sb);
	if (sa->size > 5 && ft_stack_is_sorted(sa) == 0) 
		ft_sort_more(sa, sb);
}
