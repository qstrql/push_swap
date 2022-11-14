/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:35:01 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/09 21:09:25 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/ft_printf.h"
#include "libft/INCLUDES/libft.h"

void	ft_printf_stack(t_stack *sa, t_stack *sb)
{
	int	i;
	int	j;

	i = sa->size - 1;
	j = 1;
	while (j <= sa->size)
	{
		ft_printf("a : (%d) | [%d]\n", i, sa->tab[i]);
		j++;
		i--;
	}
	ft_printf("\n");
	i = sb->size - 1;
	j = 1;
	while (j <= sb->size)
	{
		ft_printf("b : (%d) | [%d]\n", i, sb->tab[i]);
		j++;
		i--;
	}
	ft_printf("\n");
}
