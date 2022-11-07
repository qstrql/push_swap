/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:35:01 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/07 14:04:18 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/ft_printf.h"
#include "libft/INCLUDES/libft.h"

void	ft_printf_stack(t_stack *s, char c)
{
	int	i;
	int	j;

	i = s->size - 1;
	j = 1;
	while (j <= s->size)
	{
		ft_printf("%c : (%d) | [%d]\n", c, i, s->tab[i]);
		j++;
		i--;
	}
	ft_printf("\n");
}
