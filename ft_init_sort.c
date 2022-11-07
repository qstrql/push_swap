/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/07 14:10:36 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/INCLUDES/ft_printf.h"
#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

	//split le tab en 3 > push les 2 plus petits tier dans b, ra les plus grand
	//repeter jusqu'a ce qu'il reste 3 nb dans sa > trier ces 3 nb
	//
//parse sb et trouver le nombre qui prend le moin de coup pour etre push dans sa
	//(ra+rb / ra+rrb / rra+rb / rra+rrb) > effectuer ce qui prend le moin
	//repeat tant que pb est pas vide
	//rotate pa pour avoir le bon sens

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

void	ft_smart_rotate(t_stack *sa, int key)
{
	if (ft_index_of(0, sa->tab, sa->size) >= sa->size / 2)
		while (sa->tab[sa->size - 1] != key)
			rotate(sa, 'a');
	else
		while (sa->tab[sa->size - 1] != key)
			reverse(sa, 'a');
}

void	ft_sort_five(t_stack *sa, t_stack *sb)
{
	ft_smart_rotate(sa , 0);
	push_b(sa, sb);
	push_b(sa, sb);
	ft_sort_three(sa);
	push_a(sa, sb);
	push_a(sa ,sb);
}

void	ft_sort_more(t_stack *sa, t_stack *sb)
{
	int	i;
	int	pushed;
	int	size;

	i = 0;
	pushed = 0;
	size = sa->size;
	ft_printf_stack(sa, 'a');
	ft_printf_stack(sb, 'b');
	while (size > 5 && i < size && pushed < size / 2)
	{
		if (sa->tab[sa->size - 1] <= size / 2)
		{
			push_b(sa, sb);
			pushed++;
		}
		else
			rotate(sa, 'a');
		i++;
	}
	ft_printf_stack(sa, 'a');
	ft_printf_stack(sb, 'b');
	while (size - pushed > 3)
	{
		push_b(sa, sb);
		pushed++;
	}
	ft_sort_three(sa);
	ft_printf_stack(sa, 'a');
	ft_printf_stack(sb, 'b');
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
