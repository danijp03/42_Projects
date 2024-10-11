/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:03:43 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/08 21:30:32 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char	*buffer;
	static char *full_buff;
	static char	*aux_buffer;
	static char	*buffer_2;
	static char	*buffer_3;
	int	bytes_read;
	int i;
	int	len_buffer2;
	int	len_buffer3;
	static int	last_read;
	char	*tmp;

	i = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		last_read = bytes_read;
		full_buff = ft_strdup(buffer);
	}
	else if (bytes_read == 0 && *aux_buffer != '\0')
	{
		ft_bzero(buffer, BUFFER_SIZE);		
		while (*aux_buffer != '\n' && *aux_buffer != '\0')
		{
			buffer[i] = *aux_buffer;
			i++;
			aux_buffer++;
		}
		aux_buffer++;
		return(buffer);
	}
	while (buffer != NULL && bytes_read != 0)
	{
		buffer[last_read] = '\0';
		if (aux_buffer == NULL)
			aux_buffer = ft_strdup("");
		if (step_in_buffer(full_buff) >= 1 && aux_buffer != NULL)
		{
			len_buffer2 = strlen_antesdelsalto(full_buff);
			buffer_2 = ft_strdup_antesdelsalto(full_buff, len_buffer2);
			len_buffer3 = strlen_despuesdelsalto(full_buff);
			buffer_3 = ft_strdup_despuesdelsalto(full_buff, len_buffer3);
			buffer = ft_strjoin(aux_buffer, buffer_2);
			aux_buffer = ft_strdup(buffer_3);
		}
		if (step_at_the_end(buffer) == 1)
			{
				del_step(buffer);
				return (buffer);
			}
		else if (buffer_3 != NULL)
			aux_buffer = ft_strjoin(aux_buffer, full_buff);
		else if (buffer_3 == NULL && aux_buffer != NULL)
			aux_buffer = ft_strjoin(aux_buffer, full_buff);
		else
			aux_buffer = ft_strdup(full_buff);
	} 
	return (NULL);
}

#include <stdio.h>

int	main(void)
{
	int	fd;
	fd = open("text.txt", O_RDONLY);
	char	*buff;
	int	i;
	i = 0;
	buff = "1";
	while (buff != NULL)
	{
		buff = get_next_line(fd);
		if (buff != NULL)
			printf("Linea [%d] %s\n", ++i, buff);
		free(buff);
	}
	close(fd);
	return (0);	
}
