/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/26 18:34:08 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>

#include <stdio.h>

char	*ft_realloc(char *joined, char *argv)
{
	char	*re_allocd;

	re_allocd = ft_strjoin(joined, argv);
	free(joined);
	return (re_allocd);
}

int main(int argc, char **argv)
{
	int	i;
	char *joined;
	char **splited;
	
	i = 1;
	joined = ft_calloc(1, sizeof(char));
	splited = ft_calloc(argc, sizeof(char *));
	if (joined == NULL || splited == NULL)
		return (-1);
	while (i < argc)
	{
		joined = ft_realloc(joined, argv[i]);
		joined = ft_realloc(joined, " ");
		i++;
	}
	printf("%s\n", joined);
	splited = ft_split(joined, ' ');
	i = 0;
	while (i < argc)
	{
		printf("%s\n", splited[i]);
		i++;
	}
	return (0);
}
