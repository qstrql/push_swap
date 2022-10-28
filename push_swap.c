/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/28 16:49:36 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>

#include <stdio.h>

static char	*ft_realloc(char *joined, char *argv)
{
	char	*re_allocd;

	re_allocd = ft_strjoin(joined, argv);
	free(joined);
	return (re_allocd);
}

static char **ft_process_args(int argc, char **argv)
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
	splited = ft_split(joined, ' ');
	return (splited);
}

static void ft_verrif_args(char *argv)
{
	int	i;
	int	is_space;
	int	is_sign;

	i = 0;
	is_space = 1;
	is_sign = 1;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 1)
		{
			is_space = 0;
			is_sign = 0;
		}
		else if (argv[i] == ' ' && is_space < 2)
			is_space += 1;
		else if ((argv[i] == '+' || argv[i] == '-') && is_sign < 2)
			is_sign += 1;
		else
			ft_error();
		i++;
	}
}

static void	ft_are_args_ok(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error();
		i++;
	}
	i = 1;
	while (i < argc)
		ft_verrif_args(argv[i++]);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		ft_error();
	ft_are_args_ok(argc, argv);
	ft_process_args(argc, argv);
	return (0);
}
