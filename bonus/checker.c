/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:16:33 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/15 18:05:08 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../libft/INCLUDES/libft.h"
#include <stdlib.h>

void	ft_do_moves(t_stack *sa, t_stack *sb, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(sa);
	if (ft_strcmp(line, "sb\n") == 0)
		swap(sb);
	if (ft_strcmp(line, "pa\n") == 0)
		push_a(sa, sb);
	if (ft_strcmp(line, "pb\n") == 0)
		push_b(sa, sb);
	if (ft_strcmp(line, "ra\n") == 0)
		rotate(sa);
	if (ft_strcmp(line, "rb\n") == 0)
		rotate(sb);
	if (ft_strcmp(line, "rra\n") == 0)
		reverse(sa);
	if (ft_strcmp(line, "rrb\n") == 0)
		reverse(sb);
	if (ft_strcmp(line, "ss\n") == 0)
		ss(sa, sb);
	if (ft_strcmp(line, "rr\n") == 0)
		rr(sa, sb);
	if (ft_strcmp(line, "rrr\n") == 0)
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
	
	line = gnl(0);
	while (line != NULL)
	{
		ft_do_moves(sa, sb, line);
		free(line);
		line = gnl(0);
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
