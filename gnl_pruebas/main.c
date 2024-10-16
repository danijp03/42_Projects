/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:55:17 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/16 19:22:41 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*buff;
	int	i;
	
	i = 0;
	buff = "";
	fd = open("text.txt", O_RDONLY);
	while (buff != NULL)
	{
		buff = get_next_line(fd);
		if (buff != NULL)
			printf("[Linea %d]: %s\n", i++, buff);
		free(buff);		
	}
	return (0);
}
