/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:20:10 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/15 13:00:13 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char	*s)
{
	char	*aux;
	int	i;

	i = 0;
	aux = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	while (s[i] != '\0')
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

int	ft_strlen_sp(char *str)
{
	int	i;
	
	i = 0;
	while (*str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

int	step_in_buff(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			c++;
		i++;
	}
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
	{
        char    *str;
        int             i;

        i = 0;
        str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
        if (str == NULL)
                return (NULL);
        while (*s1 != '\0')
        {
                str[i] = *s1;
                i++;
                s1++;
        }
        while (*s2 != '\0')
        {
                str[i] = *s2;
                s2++;
                i++;
        }
        str[i] = '\0';
        return (str);
}

