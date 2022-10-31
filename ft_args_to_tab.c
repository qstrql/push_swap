/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:23:14 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 14:32:59 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>
#include <limits.h>

long	ft_atol(const char *nptr)
{
	int		i;
	int		neg;
	long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * neg);
}

int	*ft_args_to_tab(char **splitted, t_stack *stack)
{
	int		i;
	long	n;
	int		*tab;

	tab = ft_calloc(stack->size + 1, sizeof(int));
	i = 0;
	while (splitted[i] != NULL)
	{
		n = ft_atol(splitted[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_all(splitted);
			free(tab);
			ft_error();
		}
		tab[i] = n;
		i++;
	}
	free_all(splitted);
	return (tab);
}
