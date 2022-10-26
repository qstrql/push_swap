/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:44:53 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/26 17:22:22 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Swap the first 2 elements at the top of stack a.*/
void	sa(t_list **lst);
/*Swap the first 2 elements at the top of stack b*/
void	sb(t_list **lst);
/*sa and sb at the same time*/
void	ss(t_list **lst);

/*Take the first element at the top of b and put it at the top of a.*/
void	pa(t_list **lst);
/*Take the first element at the top of a and put it at the top of b.*/
void	pb(t_list **lst);

/*Shift up all elements of stack a by 1.*/
void	ra(t_list **lst);
/*Shift up all elements of stack b by 1.*/
void	rb(t_list **lst);
/*ra and rb at the same time.*/
void	rr(t_list **lst);

/*Shift down all elements of stack a by 1.*/
void	rra(t_list **lst);
/*Shift down all elements of stack b by 1.*/
void	rrb(t_list **lst);
/*rra and rrb at the same time.*/
void	rrr(t_list **lst);
