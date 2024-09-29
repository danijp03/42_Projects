/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:20:53 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/25 20:04:41 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	str = malloc((size + 1) * sizeof(char));
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
