/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:38:30 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/17 20:50:17 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i <= (size - 1))
	{
		dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}