/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:58:31 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/24 11:21:53 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	while (i < argc) 
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
