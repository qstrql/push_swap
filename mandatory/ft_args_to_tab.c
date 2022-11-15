/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:23:14 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/05 21:44:04 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/INCLUDES/libft.h"
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

int	ft_duplicates(int *tab, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (tab[i] == tab[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_args_to_tab(char **splitted, t_stack *stack)
{
	int		i;
	int		j;
	long	n;
	int		*tab;

	tab = ft_calloc(stack->size + 1, sizeof(int));
	j = 0;
	i = stack->size - 1;
	while (i >= 0)
	{
		n = ft_atol(splitted[j]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(splitted, stack, tab);
		tab[i] = n;
		i--;
		j++;
	}
	if (ft_duplicates(tab, stack) == 1)
		ft_error(splitted, stack, tab);
	free_all(splitted);
	return (tab);
}
