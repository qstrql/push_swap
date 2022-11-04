/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:28:13 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/04 14:30:57 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

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

void	ft_error(char **splitted, t_stack *sa, t_stack *sb, int *tab)
{
	write(2, "Error\n", 6);
	if (tab)
		free(tab);
	if (splitted)
		free_all(splitted);
	if (sa && sb)
		free_stacks(sa, sb);
	exit(EXIT_FAILURE);
}
