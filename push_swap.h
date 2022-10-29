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
long	ft_atol(const char *nptr);
//push_swap.c

#endif
