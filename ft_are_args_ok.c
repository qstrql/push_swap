/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_args_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:10 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 17:21:29 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

void	ft_verif_args(char *argv)
{
	int	i;
	int	is_sign;

	i = 0;
	is_sign = 1;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 1)
			is_sign = 0;
		else if (argv[i] == ' ')
			i++;
		else if ((argv[i] == '+' || argv[i] == '-') && is_sign < 2)
			is_sign += 1;
		else
			ft_error();
		i++;
	}
}

void	ft_are_args_ok(int argc, char **argv)
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
	{
		ft_verif_args(argv[i]);
		i++;
	}
}
