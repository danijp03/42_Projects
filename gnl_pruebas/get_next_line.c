/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:05:07 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/20 13:24:10 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*big_next_line(char *join, char	*res)
{
	int	i;

	i = 0;
	while (*join != '\n')
	{
		res[i] = *join;
		join++;
		i++;
	}
	join++;
	res[i++] = '\n';
	res[i] = '\0';
	return (join);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*res;
	static char	*join;
	int	bytesleidos;
	int	i;

	if (!join)
		join = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);	
	while ((bytesleidos = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesleidos] = '\0';
		join = ft_strjoin(join, buffer);
		if (step_in_buff(join) >= 1)
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
	if (bytesleidos == 0 && *join != '\0')
	{
		if (*join == '\n')
		{
			res = malloc(1);
			res[0] = join[0];
			join++;
			return (res);
		}
		else
		{
			res = malloc((ft_strlen_sp(join) + 1) * sizeof(char));
			join = big_next_line(join, res);
			return (res);
		}
	}
	return (NULL);
}
