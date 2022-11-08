/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/08 18:05:16 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/INCLUDES/ft_printf.h"
#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

	//split le tab en 3 > push les 2 plus petits tier dans b, ra les plus grand
	//repeter jusqu'a ce qu'il reste 3 nb dans sa > trier ces 3 nb
	//
	//get where each number goes
	//calculate least move
	//do moves
	//repeat tant que pb est pas vide
	//smart rotate

int	ft_stack_is_sorted(t_stack *sa)
{
	int	i;

	i = 0;
	while (i < sa->size)
	{
		if (sa->tab[i] < sa->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_three(t_stack *sa)
{
	int	i;
	int	j;
	int	k;

	i = sa->size - 1;
	j = sa->size - 2;
	k = sa->size - 3;
	if (sa->tab[i] > sa->tab[j] && sa->tab[i] > sa->tab[k])
		rotate(sa, 'a');
	else if (sa->tab[j] > sa->tab[k] && sa->tab[j] > sa->tab[i])
		reverse(sa, 'a');
	if (sa->tab[i] > sa->tab[j])
		swap(sa, 'a');
}

void	ft_smart_rotate_sb(t_stack *sb, int key)
{
	if (ft_index_of(key, sb->tab, sb->size) >= sb->size / 2)
		while (sb->tab[sb->size - 1] != key)
			rotate(sb, 'b');
	else
		while (sb->tab[sb->size - 1] != key)
			reverse(sb, 'b');
}

void	ft_smart_rotate_sa(t_stack *sa, int key)
{
	if (ft_index_of(key, sa->tab, sa->size) >= sa->size / 2)
		while (sa->tab[sa->size - 1] != key)
			rotate(sa, 'a');
	else
		while (sa->tab[sa->size - 1] != key)
			reverse(sa, 'a');
}

void	ft_sort_five(t_stack *sa, t_stack *sb)
{
	ft_smart_rotate_sa(sa , 0);
	push_b(sa, sb);
	if (sa->size == 4)
	{
		ft_smart_rotate_sa(sa , 1);
		push_b(sa, sb);
	}
	ft_sort_three(sa);
	push_a(sa, sb);
	if (sb->size == 1)
		push_a(sa, sb);
}

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
	while (++j <= 3)
	{
		while ((i + k++) < sa->max_size && pushed * 4 < sa->max_size * j)
		{
				if (sa->tab[sa->size - 1] * 4 <= sa->max_size * j)
				{
					push_b(sa, sb);
					pushed++;
				}
				else
					rotate(sa, 'a');
		}
		i += 25;
		k = 0;
		pushed = 0;
	}
}

void	ft_sort_more(t_stack *sa, t_stack *sb)
{
	int	i;

	i = 1;
	ft_push_all(sa, sb);
	while (sa->size != 0)
		push_b(sa, sb);
	while (sb->size != 0)
	{
		ft_smart_rotate_sb(sb, sa->max_size - i);
		push_a(sa, sb);
		i++;
	}
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
	if (sa->size > 5) 
	{
		ft_sort_more(sa, sb);
		return (1);
	}
	return (0);
}
