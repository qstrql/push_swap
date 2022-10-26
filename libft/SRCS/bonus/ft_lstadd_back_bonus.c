/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:15:21 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/14 14:40:34 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (lst != 0)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
	}
}
