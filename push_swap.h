/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:30:57 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/29 19:44:48 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/INCLUDES/libft.h"
# include <stddef.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
}			   t_stack;

//ft_utils.c
void	ft_error(void);
void	free_all(char **splited);

//ft_are_args_ok.c
void	ft_are_args_ok(int argc, char **argv);
void	ft_duplicates(char **argv);
int	ft_args_cmp(char *s1, char *s2);
void	ft_verif_args(char *argv);
int	ft_zero_check(char *argv);

//ft_process_args.c
char	**ft_process_args(int argc, char **argv, t_stack *stack);
int	ft_count_tab_size(char *joined);
char	*ft_realloc(char *joined, char *argv);

//ft_args_to_tab.c
int	*ft_args_to_tab(char **splitted, t_stack *stack);
long	ft_atol(const char *nptr);

#endif
