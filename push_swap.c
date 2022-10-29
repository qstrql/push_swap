/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/29 20:12:17 by mjouot           ###   ########.fr       */
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

int	ft_count_tab_size(char *joined)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (joined[i] != '\0')
	{
		if (joined[i] == ' ')
			count++;	
		i++;
	}
	count += 1;
	return (count);
}

static char **ft_process_args(int argc, char **argv, t_stack *stack)
{
	int	i;
	char *joined;
	char **splitted;
	
	i = 1;
	joined = ft_calloc(1, sizeof(char));
	if (joined == NULL)
		exit(EXIT_FAILURE);
	while (i < argc)
	{
		joined = ft_realloc(joined, argv[i]);
		joined = ft_realloc(joined, " ");
		i++;
	}
	stack->size = ft_count_tab_size(joined);
	splitted = ft_calloc(stack->size + 1, sizeof(char *));
	if (splitted == NULL)
		exit(EXIT_FAILURE);
	splitted = ft_split(joined, ' ');
	free(joined);
	return (splitted);
}

static void ft_verif_args(char *argv)
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
		ft_verif_args(argv[i++]);
}

long	ft_atol(const char *nptr)
{
	int	i;
	int	neg;
	long	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * neg);
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
	free (splitted);
}

int *ft_args_to_tab(char **splitted)
{
	int	i;
	long n;
	int *tab;
	
	while (splitted[i] != NULL)
		i++;
	tab = ft_calloc(i + 1, sizeof(int));
	i = 0;
	while (splitted[i] != NULL)
	{
		n = ft_atol(splitted[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			free_all(splitted);
			free(tab);
			ft_error();
		}
		tab[i] = n;
		i++;
	}
	free_all(splitted);
	return (tab);
}

int main(int argc, char **argv)
{
	char **splitted;
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (argc < 2)
		ft_error();
	ft_are_args_ok(argc, argv);
	splitted = ft_process_args(argc, argv, stack);
	stack->tab = ft_args_to_tab(splitted);
	free(stack->tab);
	free(stack);
	return (0);
}
