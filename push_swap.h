/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:30:57 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/27 11:33:01 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/INCLUDES/libft.h"
# include <stddef.h>

void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst);

void	pa(t_list **lst);
void	pb(t_list **lst);

void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **lst);

void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **lst);

//ft_utils.c
void	ft_error(void);

//push_swap.c
char	*ft_realloc(char *joined, char *argv);
char	**ft_process_args(int argc, char **argv);

#endif
