/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:06:24 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/09 21:25:01 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/ft_printf.h"
#include "libft/INCLUDES/libft.h"

void	ft_printf_target(t_stack *sb)
{
	int	i;
	int	j;

	i = sb->size - 1;
	j = 1;
	while (j <= sb->size)
	{
		ft_printf("target b : (%d) | [%d] > [%d]\n", i, sb->tab[i], sb->target[i]);
		j++;
		i--;
	}
	ft_printf("\n");
}
