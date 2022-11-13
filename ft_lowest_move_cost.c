/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowest_move_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:29:58 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/13 19:27:48 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

int	ft_get_cost_b(t_stack *sb, int key_b, int i)
{
	sb->cost_b = sb->size - 1 - i;
	if (ft_index_of(key_b, sb->tab, sb->size) >= sb->size / 2)
		sb->cost_b = (sb->size - 1 - sb->size - i);
	return (sb->cost_b);
}

int	ft_get_cost_a(t_stack *sa, t_stack *sb, int i)
{
	sb->cost_a = sa->size - 1 - sa->size - sb->target[i];
	if (sb->target[i] >= sa->size / 2)
		sb->cost_a = sa->size - 1 - sb->target[i];
	return (sb->cost_a);
}

int	ft_lowest_move_cost(t_stack *sa, t_stack *sb)
{
	int	i;
	int	save;
	int	cost_a;
	int	cost_b;

	i = 0;
	save = 0;
	cost_a = 100;
	cost_b = 100;
	while (i != sb->size)
	{
		ft_get_cost_a(sa, sb, i);
		ft_get_cost_b(sb, sb->size - i, i);
		if (ft_abs(sb->cost_a) + ft_abs(sb->cost_b) < cost_a + cost_b)
		{
			cost_a = ft_abs(sb->cost_a);
			cost_b = ft_abs(sb->cost_b);
			save = i;
		}
		i++;
	}
	return (save);
}
