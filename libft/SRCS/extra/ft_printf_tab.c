/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:24:28 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/30 23:27:27 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"
#include "../../INCLUDES/libft.h"

void	ft_printf_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("tab[%d] : %d\n", i, tab[i]);
		i++;
	}
}