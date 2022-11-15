/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:28:13 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/07 13:18:53 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{	
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
}

void	free_all(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

void	ft_error(char **splitted, t_stack *sa, int *tab)
{
	if (tab)
		free(tab);
	if (splitted)
		free_all(splitted);
	if (sa)
	{
		free(sa->tab);
		free(sa);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
