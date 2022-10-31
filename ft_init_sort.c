/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:24:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 19:54:14 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"


void	ft_sort_more(t_stack *sa, t_stack *sb)
{

}

void	ft_sort_three(t_stack *sa)
{
	if (sa->tab[0] > sa->tab[1] && sa->tab[0] > sa->tab[2])
		rotate(sa, 'a');
	else if (sa->tab[1] > sa->tab[0] && sa->tab[1] > sa->tab[2])
		reverse(sa, 'a');
	if (sa->tab[0] > sa->tab[1])
		swap(sa, 'a');
}

int	ft_init_sort(t_stack *sa, t_stack *sb)
{
	if (sa->size == 1)
		return (1);
	if (sa->size == 2)
	{
		if (sa->tab[0] > sa->tab[1])
			swap(sa, 'a');
		return (1);
	}
	if (sa->size == 3)
	{
		ft_sort_three(sa);
		return (1);
	}
	if (sa->size > 3)
	{
		ft_sort_more(sa, sb);
		return (1);
	}
	return (0);
}
