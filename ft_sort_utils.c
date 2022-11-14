/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:24:57 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/14 15:58:06 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/INCLUDES/ft_printf.h"
#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

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
