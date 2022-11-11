/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/11 23:32:21 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/INCLUDES/ft_printf.h"
#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

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
	int	save;

	save = 0;
	ft_push_all(sa, sb); //segfault if 5 < size < 16
	while (sa->size != 3)
		push_b(sa, sb);	
	ft_sort_three(sa);
	while (sb->size != 0)
	{
		ft_target_position(sa, sb);
		save = ft_lowest_move_cost(sa, sb);
		ft_get_cost_a(sa, sb, sb->size - save, save);
		ft_get_cost_b(sb, sb->size - save, save);
		ft_exec_moves(sa, sb);
	}
	if (ft_stack_is_sorted(sa) == 0)
		ft_smart_rotate_sa(sa, 0);
	/*ft_target_position(sa, sb);
	save = ft_lowest_move_cost(sa, sb);
	ft_get_cost_a(sa, sb, sb->size - save, save);
	ft_get_cost_b(sb, sb->size - save, save);
	reverse(sb, 'b');
	push_a(sa, sb);
	ft_target_position(sa, sb);
	save = ft_lowest_move_cost(sa, sb);
	ft_get_cost_a(sa, sb, sb->size - save, save);
	ft_get_cost_b(sb, sb->size - save, save);
	reverse(sb, 'b');
	push_a(sa, sb);
	ft_target_position(sa, sb);
	save = ft_lowest_move_cost(sa, sb);
	ft_get_cost_a(sa, sb, sb->size - save, save);
	ft_get_cost_b(sb, sb->size - save, save);
	// ft_exec_moves(sa, sb);
	ft_printf_stack(sb, sa);
	ft_printf_target(sb);
	ft_printf("value : %d\n", sb->tab[save]);
	ft_printf("save : %d\n", save);
	ft_printf("cost a : %d\n", sb->cost_a);
	ft_printf("cost b : %d\n\n", sb->cost_b);*/
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
