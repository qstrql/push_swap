/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:58:54 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/02 16:03:46 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/INCLUDES/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**splitted;
	t_stack	*sa;
	t_stack *sb;

	if (argc < 2)
		ft_error();
	ft_are_args_ok(argc, argv);
	sa = ft_calloc(1, sizeof(t_stack));
	sb = ft_calloc(1, sizeof(t_stack));
	splitted = ft_process_args(argc, argv, sa);
	sa->tab = ft_args_to_tab(splitted, sa);
	ft_normalize(sa);
	sb->tab = ft_calloc(sa->size + 1, sizeof(int));
	ft_init_sort(sa, sb);
	free_stacks(sa, sb);
	return (0);
}
//normaliser les valeurs
//stocker les instructions dans un tab 
