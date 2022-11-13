/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:48:36 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/13 16:53:10 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

void	rr(t_stack *sa, t_stack *sb)
{
	int	tmp_a;
	int	tmp_b;
	
	ft_printf("rr\n");
	tmp_a = sa->tab[sa->size - 1];
	tmp_b = sb->tab[sb->size - 1];
	ft_memmove(sa->tab + 1, sa->tab, sa->size * sizeof(int));
	sa->tab[0] = tmp_a;
	ft_memmove(sb->tab + 1, sb->tab, sb->size * sizeof(int));
	sb->tab[0] = tmp_b;
}

void	rrr(t_stack *sa, t_stack *sb)
{
	int	tmp_a;
	int	tmp_b;
	
	ft_printf("rrr\n");
	tmp_a = sa->tab[0];
	tmp_b = sb->tab[0];
	ft_memmove(sa->tab, sa->tab + 1, sa->size * sizeof(int));
	sa->tab[sa->size - 1] = tmp_a;
	ft_memmove(sb->tab, sb->tab + 1, sb->size * sizeof(int));
	sb->tab[sb->size - 1] = tmp_b;
}
