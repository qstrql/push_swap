/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/09 21:07:26 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <limits.h>

	//split le tab en 3 > push les 2 plus petits tier dans b, ra les plus grand
	//repeter jusqu'a ce qu'il reste 3 nb dans sa > trier ces 3 nb
	//
	//get where each number goes
	//calculate least move
	//do moves
	//repeat tant que pb est pas vide
	//smart rotate

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
		i += 20;
		k = 0;
		pushed = 0;
	}
}

int	ft_target(t_stack *sa, int key_b, int target)
{
	int	i;
	int	idx;

	i = 0;
	idx = INT_MAX;
	while (i < sa->size - 1)
	{
		if (sa->tab[sa->size - i] > key_b && sa->tab[sa->size - i] < idx)
		{
			idx = sa->tab[sa->size - i];
			target = sa->tab[sa->size - i];
		}
		i++;
	}
	if (idx != INT_MAX)
		return (target);
	i = 0;
	while (i < sa->size - 1)
	{
		if (sa->tab[sa->size - i] < idx)
		{
			idx = sa->tab[sa->size - i];
			target = sa->tab[sa->size - i];
		}
		i++;
	}
	return (target);
}

void	ft_target_position(t_stack *sa, t_stack *sb)
{
	int	i;
	int	j;
	int	target;

	i = 0;
	j = sb->size - 1;
	target = 0;
	while (i < sb->size - 1)
	{
		target = ft_target(sa, sb->tab[sb->size - i], target);
		sb->target[j] = target;
		j--;
		i++;
	}
}

void	ft_sort_more(t_stack *sa, t_stack *sb)
{
	int	i;

	i = 1;
	ft_push_all(sa, sb);
	while (sa->size != 3)
		push_b(sa, sb);
	ft_sort_three(sa);
	ft_target_position(sa, sb);
	ft_printf_stack(sa, sb);
	ft_printf_target(sb);
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
