/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:44:53 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/24 10:58:19 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(); //swap top 2 in pile A
void	swap_b(); //swap top 2 in pile B
void	swap_ab();//swap top 2 in both piles

void	push_a(); //push top from B to A
void	push_b(); //push top from A to B

void	rotate_a();//shift 1 pos upward (first becomes last) in A
void	rotate_b();//shift 1 pos upward (first becomes last) in B
void	rotate_ab();//shift 1 pos upward in both piles

void	r_rotate_a();//shift 1 pos downward (last becomes first) in A
void	r_rotate_b();//shift 1 pos downward (last becomes first) in B
void	r_rotate_ab();//shift 1 pos downward in both piles
