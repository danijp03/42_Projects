/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:18:26 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/17 20:37:09 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(char *dest, const char *src, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = dest;
	i = 0;
	while (i < n && src[i] != '\0')
	{
		tmp[i] = src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = tmp[i];
		i++;
	}
	return (dest);
}
