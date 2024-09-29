/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:24:29 by dani              #+#    #+#             */
/*   Updated: 2024/09/26 23:03:42 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*aux;

	aux = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			aux = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)aux);
}
