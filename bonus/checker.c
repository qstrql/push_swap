/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:16:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/15 20:26:57 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/INCLUDES/libft.h"
#include <stdlib.h>

void	ft_do_moves(t_stack *sa, t_stack *sb, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(sa);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(sb);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a(sa, sb);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b(sa, sb);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(sa);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(sb);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse(sa);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse(sb);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(sa, sb);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(sa, sb);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
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
			break ;
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
