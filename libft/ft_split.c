/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:48:19 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/29 21:36:22 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	in_word;

	i = 0;
	words = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !in_word)
		{
			words++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (words);
}

int	word_length(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

char	**allocate_memory(char const *s, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**arr;

	word_count = count_words(s, c);
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
			return (NULL);
		j += word_length(s, c, j);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	fill_array(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] != '\0')
		{
			j = 0;
			while (s[k] != c && s[k] != '\0')
				arr[i][j++] = s[k++];
			arr[i][j] = '\0';
			i++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = allocate_memory(s, c);
	if (arr == NULL)
		return (NULL);
	fill_array(arr, s, c);
	return (arr);
}
