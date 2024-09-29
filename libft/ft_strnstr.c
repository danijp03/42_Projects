/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:34:57 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/27 14:06:47 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*aux;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == *little)
		{
			aux = &(big[i]);
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)aux);
		}
		i++;
	}
	return (NULL);
}
