/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:05:07 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/15 13:30:15 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char	*buffer;
	char	*res;
	static char	*join;
	int	bytesleidos;
	int	i;

	save = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);	
	while ((bytesleidos = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesleidos] = '\0';
		if (!save)
			save = ft_strdup("");
		join = ft_strjoin(save, buffer);
		save = ft_strdup(buffer);
		if (step_in_buff(join) == 1)
		{
			i = 0;
			res = malloc((ft_strlen_sp(join) + 1) * sizeof(char));
			while (*join != '\n')
			{
				res[i] = *join;
				i++;
				join++;
			}
			join++;
			res[i++] = '\n';
			res[i] = '\0';
			return (res);
		}
	}
}
