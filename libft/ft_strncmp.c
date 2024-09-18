/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:46:30 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/18 17:08:24 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 != '\0' && *s2 != '\0') && i < n)
	{
		if (*s1 == *s2)
			return(ft_strncmp(s1 + 1, s2 + 1, n - 1));
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	size_t	i;
	(void)argc;

	i = ft_strncmp(argv[1], argv[2], 3);
	printf("%zu\n", i);
	return 0;
}
