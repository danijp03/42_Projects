/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:03:43 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/06 20:13:53 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 4

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*aux_buffer;
	static char	*buffer_2;
	static char	*buffer_3;
	int	bytes_read;
	int	len_buffer2;
	int	len_buffer3;

	if (buffer == NULL)
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (step_in_buffer(buffer) == 1)
		{
			len_buffer2 = strlen_antesdelsalto(buffer);
			buffer_2 = ft_strdup_antesdelsalto(buffer, len_buffer2);
			len_buffer3 = strlen_despuesdelsalto(buffer);
			buffer_3 = ft_strdup_despuesdelsalto(buffer, len_buffer3);
			buffer = ft_strjoin(aux_buffer, buffer_2);
		}
		if (step_at_the_end(buffer) == 1)
			return (buffer);
		aux_buffer = ft_strdup(buffer);
	}
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
	while (*buff != '\0')
	{
		buff = get_next_line(fd);
		printf("[%d] %s\n", ++i, buff);
		free(buff);
	}
	close(fd);
	return (0);	
}
