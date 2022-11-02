/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/02 18:28:44 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

//split le tab en 3 > push les 2 plus petits tier dans b, ra les plus grand
//repeter jusqu'a ce qu'il reste 3 nb dans sa > trier ces 3 nb
//
//parse sb et trouver le nombre qui prend le moin de coup pour etre push dans sa
//(ra+rb / ra+rrb / rra+rb / rra+rrb) > effectuer ce qui prend le moin
//repeat tant que pb est pas vide
//rotate pa pour avoir le bon sens
/*
void	ft_sort_more(t_stack *sa, t_stack *sb)
{

}
*/
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

void	ft_sort_five(t_stack *sa, t_stack *sb)
{
	ft_printf_stack(sa, sb);
	if (sa->tab[sa->size - 1] == (sa->size - 1))
		rotate(sa, 'a');
	if (sa->tab[sa->size - 2] == (sa->size - 1))
		reverse(sa, 'a');
	push_b(sa, sb);
	push_b(sa, sb);
	ft_printf_stack(sa, sb);
	ft_sort_three(sa);
	while (sa->tab[sa->size - 1] < sb->tab[sb->size - 1])
		rotate(sa, 'a');
	push_a(sa, sb);
	ft_printf_stack(sa, sb);
	while (sa->tab[sa->size - 1] < sb->tab[sb->size - 1])
		rotate(sa, 'a');
	push_a(sa, sb);
	ft_printf_stack(sa, sb);
	ft_printf("\n");
	if (ft_index_of(0, sa->tab, sa->size) >= 2)
	{
		while (sa->tab[sa->size - 1] != 0)
			rotate(sa, 'a');
	}
	else
	{
		while (sa->tab[sa->size - 1] != 0)
			reverse(sa, 'a');
	}
	ft_printf_stack(sa, sb);
}

int	ft_init_sort(t_stack *sa, t_stack *sb)
{
	(void)sb;
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
	if (sa->size == 5 && ft_stack_is_sorted(sa) == 0)
	{
		ft_sort_five(sa, sb);
		return (1);
	}
//	if (sa->size > 5) 
//	{
//		ft_sort_more(sa, sb);
//		return (1);
//	}
	return (0);
}
