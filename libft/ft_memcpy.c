/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:59:50 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/17 20:17:16 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(char	*dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (src[i] != '\0' && dest[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
