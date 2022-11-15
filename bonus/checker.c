/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:16:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/15 18:50:55 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/INCLUDES/libft.h"
#include <stdlib.h>

void	ft_do_moves(t_stack *sa, t_stack *sb, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap(sa);
	if (ft_strncmp(line, "sb", 2) == 0)
		swap(sb);
	if (ft_strncmp(line, "pa", 2) == 0)
		push_a(sa, sb);
	if (ft_strncmp(line, "pb", 2) == 0)
		push_b(sa, sb);
	if (ft_strncmp(line, "ra", 2) == 0)
		rotate(sa);
	if (ft_strncmp(line, "rb", 2) == 0)
		rotate(sb);
	if (ft_strncmp(line, "rra", 3) == 0)
		reverse(sa);
	if (ft_strncmp(line, "rrb", 3) == 0)
		reverse(sb);
	if (ft_strncmp(line, "ss", 2) == 0)
		ss(sa, sb);
	if (ft_strncmp(line, "rr", 2) == 0)
		rr(sa, sb);
	if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(sa, sb);
	else
		ft_error(NULL, NULL, NULL);
}

void	ft_check_result(t_stack *sa, t_stack *sb)
{
	if (ft_stack_is_sorted(sa) == 1 && sb->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ft_init_check(t_stack *sa, t_stack *sb)
{
	char *line;
	
	while (1)
	{
		line = gnl(0);
		if (!line || ft_strlen(line) == 0)
		{
			free(line);
			return ;
		}
		ft_do_moves(sa, sb, line);
		free(line);
	}
	ft_check_result(sa, sb);
}

int	main(int argc, char **argv)
{
	char	**splitted;
	t_stack	*sa;
	t_stack	*sb;

	if (argc <= 1)
		return (0);
	ft_are_args_ok(argc, argv);
	sa = ft_calloc(1, sizeof(t_stack));
	splitted = ft_process_args(argc, argv, sa);
	sa->tab = ft_args_to_tab(splitted, sa);
	ft_normalize(sa);
	sb = ft_calloc(1, sizeof(t_stack));
	sb->tab = ft_calloc(sa->size + 1, sizeof(int));
	sb->size = 0;
	ft_init_check(sa, sb);
	free_stacks(sa, sb);
	return (0);
}
