/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_args_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:21:10 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/31 14:32:14 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"

void	ft_verif_args(char *argv)
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

int	ft_args_cmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[i] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void	ft_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[j] != NULL)
		{
			if (ft_args_cmp(argv[i], argv[j]) == 0 && i != j)
				ft_error();
			j++;
		}
		i++;
	}
}

int	ft_zero_check(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] != '\0' && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

void	ft_are_args_ok(int argc, char **argv)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_error();
		i++;
	}
	ft_duplicates(argv);
	i = 1;
	while (i < argc)
	{
		zero += ft_zero_check(argv[i]);
		ft_verif_args(argv[i]);
		i++;
	}
	if (zero > 1)
		ft_error();
}
