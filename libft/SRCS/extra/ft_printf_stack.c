/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:35:01 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/01 13:55:55 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"
#include "../../INCLUDES/libft.h"

void	ft_printf_stack(int *tab, int len)
{
	int	i;
	int	j;

	i = len - 1;
	j = 1;
	while (j <= len)
	{
		ft_printf(" (%d) | [%d] \n", i, tab[i]);
		j++;
		i--;
	}
	ft_printf("  _  |  _  \n");
}
