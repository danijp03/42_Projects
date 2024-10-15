/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:12:39 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/15 12:41:34 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int	ft_strlen(char *s);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, void *src, size_t n);
int	ft_strlen_sp(char *str);
int	step_in_buff(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
