/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:30:57 by mjouot            #+#    #+#             */
/*   Updated: 2022/11/14 19:08:04 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/INCLUDES/libft.h"
# include <stddef.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
	int	max_size;
}				t_stack;

void	ft_printf_stack(t_stack *sa, t_stack *sb);

//ft_utils.c
void	ft_error(char **splitted, t_stack *sa, int *tab);
void	free_all(char **splited);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

//ft_are_args_ok.c
void	ft_are_args_ok(int argc, char **argv);
void	ft_verif_args(char *argv);
int		ft_zero_check(char *argv);

//ft_process_args.c
char	**ft_process_args(int argc, char **argv, t_stack *stack);
int		ft_count_tab_size(char *joined);
char	*ft_realloc(char *joined, char *argv);

//ft_args_to_tab.c
int		*ft_args_to_tab(char **splitted, t_stack *stack);
int		ft_duplicates(int *tab, t_stack *stack);
long	ft_atol(const char *nptr);

//ft_moves.c
void	swap(t_stack *stack, char c);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack, char c);
void	reverse(t_stack *stack, char c);

//ft_init_sort.c
void	ft_push_all(t_stack *sa, t_stack *sb, int div);
void	ft_sort_more(t_stack *sa, t_stack *sb);
void	ft_init_sort(t_stack *sa, t_stack *sb);

//ft_sort_utils.c
int		ft_stack_is_sorted(t_stack *sa);
void	ft_smart_rotate_sb(t_stack *sb, int key);
void	ft_smart_rotate_sa(t_stack *sa, int key);
void	ft_sort_three(t_stack *sa);
void	ft_sort_five(t_stack *sa, t_stack *sb);

//ft_normalize.c
void	ft_normalize(t_stack *stack);
int		ft_index_of(int key, int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

#endif
