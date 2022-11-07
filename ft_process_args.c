/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:17:59 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/07 13:30:51 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>

char	*ft_realloc(char *joined, char *argv)
{
	char	*re_allocd;

	re_allocd = ft_strjoin(joined, argv);
	free(joined);
	return (re_allocd);
}

int	ft_count_tab_size(char *joined)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (joined[i] != '\0')
	{
		if (joined[i] == ' ')
			while (joined[i] == ' ' && joined[i] != '\0')
				i++;
		else
		{
			while (joined[i] != ' ' && joined[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

char	**ft_process_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	*joined;
	char	**splitted;

	i = 1;
	joined = ft_calloc(1, sizeof(char));
	if (joined == NULL)
		return (NULL);
	if (argc > 1)
	{
		while (i < argc)
		{
			joined = ft_realloc(joined, argv[i]);
			if (i < argc - 1)
				joined = ft_realloc(joined, " ");
			i++;
		}
	}
	stack->size = ft_count_tab_size(joined);
	stack->max_size = ft_count_tab_size(joined);
	splitted = ft_split(joined, ' ');
	free(joined);
	return (splitted);
}
