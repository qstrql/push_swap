/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/11 11:33:12 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/INCLUDES/ft_printf.h"
#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <limits.h>

void	ft_push_all(t_stack *sa, t_stack *sb)
{
	int	i;
	int	j;
	int	k;
	int	pushed;

	i = 0;
	j = 0;
	k = 0;
	pushed = 0;
	while (++j <= 4)
	{
		while ((i + k++) < sa->max_size && pushed * 5 < sa->max_size * j)
		{
				if (sa->tab[sa->size - 1] * 5 <= sa->max_size * j)
				{
					push_b(sa, sb);
					pushed++;
				}
				else
					rotate(sa, 'a');
		}
		i += sa->max_size / 5;
		k = 0;
		pushed = 0;
	}
}

int	ft_target(t_stack *sa, int key_b)
{
	int	i;
	int	target;

	i = sa->size - 1;
	target = 500;
	while (i >= 0)
	{
		if (sa->tab[i] > key_b && sa->tab[i] < target)
			target = sa->size - 1 - i;
		i--;
	}
	if (target != 500)
		return (target);
	i = sa->size - 1;
	while (i >= 0)
	{
		if (sa->tab[i] < target)
			target = i + 1;
		i--;
	}
	return (target);
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

int	ft_get_cost(t_stack *sb, int key_b, int i)
{
	sb->cost_a = sb->target[key_b];
	sb->cost_b = i;
	return (sb->cost_a + sb->cost_b);
}

void	ft_sort_more(t_stack *sa, t_stack *sb)
{
	// int	i;
	// int	cost;
	int	save;
	// int	cost_min;

	// cost = 100;
	// cost_min = 100;
	save = 1;
	ft_push_all(sa, sb);
	while (sa->size != 3)
		push_b(sa, sb);	
	ft_sort_three(sa);
	ft_target_position(sa, sb);
/*	while (i < sb->size - 1)
	{
		cost = ft_get_cost(sb, sb->size - i, i);
		if (cost < cost_min)
		{
			cost_min = cost;
			save = i;
		}
		i++;
	}*/
	ft_get_cost(sb, sb->size - save, save);
	ft_printf_stack(sb, sa);
	ft_printf_target(sb);
	ft_printf("cost a : %d\n", sb->cost_a);
	ft_printf("cost b : %d\n", sb->cost_b);
}

int	ft_init_sort(t_stack *sa, t_stack *sb)
{
	if (sa->size == 1)
		return (1);
	if (sa->size == 2)
	{
		if (sa->tab[0] < sa->tab[1])
			swap(sa, 'a'); 
		return (1);
	}
	if (sa->size == 3 && ft_stack_is_sorted(sa) == 0)
	{
		ft_sort_three(sa);
		return (1);
	}
	if ((sa->size == 4 || sa->size == 5) && ft_stack_is_sorted(sa) == 0)
	{
		ft_sort_five(sa, sb);
		return (1);
	}
	if (sa->size > 5 && ft_stack_is_sorted(sa) == 0) 
	{
		ft_sort_more(sa, sb);
		return (1);
	}
	return (0);
}
