/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:49:08 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/16 14:41:45 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/INCLUDES/libft.h"

void	ss(t_stack *sa, t_stack *sb)
{
	int	tmp;

	if (sa->size < 2 || sb->size < 2)
		return ;
	tmp = 0;
	tmp = sa->tab[sa->size - 1];
	sa->tab[sa->size - 1] = sa->tab[sa->size - 2];
	sa->tab[sa->size - 2] = tmp;
	tmp = 0;
	tmp = sb->tab[sb->size - 1];
	sb->tab[sb->size - 1] = sb->tab[sb->size - 2];
	sb->tab[sb->size - 2] = tmp;
}

void	rr(t_stack *sa, t_stack *sb)
{
	int	tmp_a;
	int	tmp_b;

	if (sa->size < 1 || sb->size < 1)
		return ;
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

	if (sa->size < 1 || sb->size < 1)
		return ;
	tmp_a = sa->tab[0];
	tmp_b = sb->tab[0];
	ft_memmove(sa->tab, sa->tab + 1, sa->size * sizeof(int));
	sa->tab[sa->size - 1] = tmp_a;
	ft_memmove(sb->tab, sb->tab + 1, sb->size * sizeof(int));
	sb->tab[sb->size - 1] = tmp_b;
}
