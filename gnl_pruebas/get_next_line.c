/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:05:07 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/20 20:08:09 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *join, char *res)
{
	int	i;

	i = 0;
	while (join[i] != '\n' && join[i] != '\0')
	{
		res[i] = join[i];
		i++;
	}
	if (join[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (join + i);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*res;
	static char	*join;
	int	bytesleidos;
	char	*tmp;

	if (!join)
		join = ft_strdup("");
	if (!join)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);	
	while ((bytesleidos = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesleidos] = '\0';
		tmp = join;
		join = ft_strjoin(join, buffer);
		free(tmp);
		if (!join)
		{
			free(buffer);
			return (NULL);
		}
		if (step_in_buff(join) >= 1)
		{
			res = malloc((ft_strlen_sp(join) + 1) * sizeof(char));
			if (!res)
			{
				free(buffer);
				return (NULL);
			}
			join = next_line(join, res);
			free(buffer);
			return (res);
		}
	}
	free(buffer);
	if (bytesleidos == 0 && *join != '\0')
	{
		res = malloc((ft_strlen_sp(join) + 1) * sizeof(char));
		if (!res)
		{
			free(join);
			join = NULL;
			return (NULL);
		}
		join = next_line(join, res);
		return (res);
	}
	free(join);
	return (NULL);
}
