/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:24:29 by dani              #+#    #+#             */
/*   Updated: 2024/09/18 16:44:44 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*aux;
	int			i;

	i = 0;
	aux = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			aux = &(s[i]);
		i++;
	}
	return ((char *)aux);
}
