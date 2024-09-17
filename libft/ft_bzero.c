/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:50:34 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/17 19:58:36 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
