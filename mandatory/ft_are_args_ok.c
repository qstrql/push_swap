/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_args_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:10 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/16 15:59:19 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/INCLUDES/libft.h"
#include <stddef.h>

void	ft_verif_args(char *argv)
{
	int	i;
	int	is_sign;

	i = 0;
	is_sign = 1;
	while (argv[i] != '\0')
	{
		if ((argv[i] == '+' || argv[i] == '-') && argv[i - 1] != ' ' && i != 0)
			ft_error(NULL, NULL, NULL);
		if ((argv[i] == '+' || argv[i] == '-') && ft_isdigit(argv[i + 1]) == 0)
			ft_error(NULL, NULL, NULL);
		if (ft_isdigit(argv[i]) == 1 || argv[i] == ' ')
			is_sign = 0;
		else if ((argv[i] == '+' || argv[i] == '-') && is_sign < 2)
			is_sign += 1;
		else
			ft_error(NULL, NULL, NULL);
		i++;
	}
}

int	ft_space_only(char *argv)
{
	int		i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_are_args_ok(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error(NULL, NULL, NULL);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (ft_space_only(argv[i]) == 1)
			ft_error(NULL, NULL, NULL);
		ft_verif_args(argv[i]);
		i++;
	}
}
