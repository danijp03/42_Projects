/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:51:15 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/08 21:27:19 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*del_step(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	buff[i] = '\0';
	return (buff);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

int	step_at_the_end(char *buffer)
{
	int	i;

	i = 0;
	if (step_in_buffer(buffer) > 1)
		return (0);
	while (buffer[i] != '\0')
		i++;
	if (buffer[i - 1] == '\n')
		return (1);
	else
		return (0);
}

int	step_in_buffer(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
					count++;
			i++;	
		}
	return (count);
}
int	strlen_antesdelsalto(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	return (i);
}

int	strlen_despuesdelsalto(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_strdup_antesdelsalto(char *str, int len)
{
	char	*res;
	int	i;

	i = 0;
	res = malloc(len);
	while (str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\n';
	return (res); 
}

char	*ft_strdup_despuesdelsalto(char *str, int len)
{
	char	*res;
	int	i;
	int j;

	i = 0;
	j = 0;
	res = malloc(len);
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		res[j] = str[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res); 
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

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
