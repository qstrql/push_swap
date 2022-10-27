/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/27 18:33:51 by mjouot           ###   ########.fr       */
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

char **ft_process_args(int argc, char **argv)
{
	int	i;
	char *joined;
	char **splited;
	
	i = 1;
	joined = ft_calloc(1, sizeof(char));
	if (joined == NULL)
		exit(EXIT_FAILURE);
	splited = ft_calloc(argc, sizeof(char *));
	if (splited == NULL)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		joined = ft_realloc(joined, argv[i]);
		joined = ft_realloc(joined, " ");
		i++;
	}
	printf("joined : %s\n", joined);
	splited = ft_split(joined, ' ');
	int j = 1;
	while (j < argc)
		printf("%s\n", splited[j++]);
	return (splited);
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	// char	**data;

	if (argc < 2)
		ft_error();
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != ' ')
				ft_error();
			j++;
		}
		i++;
	}		
	ft_process_args(argc, argv);
	return (0);
}
