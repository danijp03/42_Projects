/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:08:24 by dajose-p          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/11 20:40:58 by dajose-p         ###   ########.fr       */
=======
/*   Updated: 2024/10/08 21:26:50 by dajose-p         ###   ########.fr       */
>>>>>>> 4b0337df341a9ce6162436f86e091890ec4e38be
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 33434
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char    *ft_strdup(const char *s);
int     ft_strlen(const char *str);
int     step_at_the_end(char *buffer);
int     step_in_buffer(char *buffer);
int     strlen_antesdelsalto(char *str);
int     strlen_despuesdelsalto(char *str);
char    *ft_strdup_antesdelsalto(char *str, int len);
char    *ft_strdup_despuesdelsalto(char *str, int len);
char    *ft_strjoin(char const *s1, char const *s2);
<<<<<<< HEAD
char	*del_step(char *buff);
=======
>>>>>>> 4b0337df341a9ce6162436f86e091890ec4e38be

#endif
