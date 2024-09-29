/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:51:27 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/29 21:04:25 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(const char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (c == s1[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	i = 0;
	start = 0;
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] != '\0' && is_in_set(set, s1[start]))
		start++;
	while ((end - 1 > 0) && is_in_set(set, s1[end - 1]))
		end--;
	str = malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
