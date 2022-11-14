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

int	ft_target(t_stack *sa, int key_b)
{
	int	i;
	int	closest;
	int	min;
	int	tmp;

	i = sa->size - 1;
	closest = 0;
	min = 500;
	while (i >= 0)
	{
		tmp = ft_abs(sa->tab[i] - key_b);
		if (min > tmp)
		{
			min = tmp;
			closest = i;
		}
		i--;
	}
	return (closest);
}

void	ft_target_position(t_stack *sa, t_stack *sb)
{
	int	i;

	i = sb->size - 1;
	while (i >= 0)
	{
		sb->target[i] = ft_target(sa, sb->tab[i]);
		i--;
	}
}

void	ft_sort_more(t_stack *sa, t_stack *sb)
{
	int	i;
	int	save;

	i = 1;
	save = 0;
	if (sa->max_size < 450)
	{
		ft_push_all(sa, sb, 9); //segfault if 5 < size < 16
		while (sa->size != 0)
			push_b(sa, sb);
		while (sb->size != 0)
		{
			ft_smart_rotate_sb(sb, sa->max_size - i);
			push_a(sa, sb);
			i++;
		}
	}
	if (sa->max_size > 450)
	{
		ft_push_all(sa, sb, 9); //segfault if 5 < size < 16
		while (sa->size != 3)
			push_b(sa, sb);	
		ft_sort_three(sa);
		while (sb->size != 0)
		{
			ft_target_position(sa, sb);
			save = ft_lowest_move_cost(sa, sb);
			ft_get_cost_a(sa, sb, save);
			ft_get_cost_b(sb, sb->size - save, save);
			ft_exec_moves(sa, sb);
		}
		ft_smart_rotate_sa(sa, 0);
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
