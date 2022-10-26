/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouot <mjouot@marvin.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:50:59 by mjouot            #+#    #+#             */
/*   Updated: 2022/10/18 16:35:01 by mjouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# include <stddef.h> //size_t

char	*get_next_line(int fd);
char	*ft_reader(char *buf, int fd);
char	*ft_get_line(char *str);
char	*ft_get_extra(char *str);

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *buf, char *line);
char	*ft_realloc(char *buf, char *line);

#endif 
