/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:07:19 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/04 14:14:07 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>


void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_index_of(int	key, int *tab, int size)
{
	int	i;

	i = 0;
	while (tab[i] != key && i < size)
		i++;
	return (i);
}

void	ft_normalize(t_stack *stack)
{
	int	i;
	int	j;
	int	key;
	int	*sorted;

	i = 0;
	sorted = ft_calloc(stack->size + 1, sizeof(int));
	while (i < stack->size)
	{
		sorted[i] = stack->tab[i];
		i++;
	}
	ft_sort_int_tab(sorted, stack->size);
	i = 0;
	key = 0;
	while (i < stack->size)
	{
		key = sorted[i];
		j = ft_index_of(key, stack->tab, stack->size);
		stack->tab[j] = i;
		i++;
	}
	free(sorted);
}
