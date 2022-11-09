/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:06:24 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/09 21:08:56 by mjouot           ###   ########.fr       */
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
		ft_printf("b : (%d) | [%d]\n", i, sb->target[i]);
		j++;
		i--;
	}
	ft_printf("\n");
}
