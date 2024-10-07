/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:08:24 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/06 20:03:48 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int	step_in_buffer(char *buffer);
int	strlen_r(char	*str);
int	strlen_l(char	*str);
char	*ft_strdup_r(char *str, int len);
char	*ft_strdup_l(char *str, int len);

#endif