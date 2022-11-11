/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowest_move_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:29:58 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/11 23:09:36 by mjouot           ###   ########.fr       */
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

int	ft_get_cost_a(t_stack *sa, t_stack *sb, int key_b, int i)
{
	(void)key_b;
	sb->cost_a = sa->size - 1 - sb->target[i];
	if (sb->target[key_b]>= sa->size / 2)
		sb->cost_a = (sa->size - 1 - sb->target[i]) * -1;
	return (sb->cost_a);
}

int	ft_lowest_move_cost(t_stack *sa, t_stack *sb)
{
	int	i;
	int	save;
	int	save_a;
	int	save_b;

	i = 0;
	save = 0;
	save_a = 100;
	save_b = 100;
	while (i < sb->size - 1)
	{
		ft_get_cost_a(sa, sb, sb->size - i, i);
		ft_get_cost_b(sb, sb->size - i, i);
		if (ft_abs(sb->cost_a) + ft_abs(sb->cost_b) < save_a + save_b)
		{
			save_a = ft_abs(sb->cost_a);
			save_b = ft_abs(sb->cost_b);
			save = i;
		}
		i++;
	}
	return (save);
}
