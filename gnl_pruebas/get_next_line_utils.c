/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:20:10 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/16 20:39:03 by dajose-p         ###   ########.fr       */
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

int     count_words(char const *s, char c)
{
        int     i;
        int     words;

        i = 0;
        words = 0;
        while (s[i] != '\0')
        {
                if (s[i] != c && (i == 0 || s[i - 1] == c))
                        words++;
                i++;
        }
        return (words);
}

int     word_length(char const *s, char c, int i)
{
        int     len;

        len = 0;
        while (s[i] != '\0' && s[i] != c)
        {
                len++;
                i++;
        }
        return (len);
}

void    free_mem(char **arr, int i)
{
        while (i-- > 0)
                free(arr[i]);
        free(arr);
}

char    **allocate_memory(char const *s, char c, int word_count)
{
        char    **arr;
        int             i;
        int             j;

        arr = malloc((word_count + 1) * sizeof(char *));
        if (arr == NULL)
                return (NULL);
        i = 0;
        j = 0;
        while (i < word_count)
        {
                while (s[j] == c)
                        j++;
                arr[i] = malloc((word_length(s, c, j) + 1) * sizeof(char));
                if (arr[i] == NULL)
                {
                        free_mem(arr, i);
                        return (NULL);
                }
                j += word_length(s, c, j);
                i++;
        }
        arr[i] = NULL;
        return (arr);
}

char    **ft_split(char const *s, char c)
{
        char    **arr;
        int             word_count;
        int             i;
        int             j;
        int             k;

        if (s == NULL)
                return (NULL);
        word_count = count_words(s, c);
        arr = allocate_memory(s, c, word_count);
        if (arr == NULL)
                return (NULL);
        i = 0;
        k = 0;
        while (i < word_count)
        {
                while (s[k] == c)
                        k++;
                j = 0;
                while (s[k] != c && s[k] != '\0')
                        arr[i][j++] = s[k++];
                arr[i][j] = '\0';
                i++;
        }
        return (arr);
}
