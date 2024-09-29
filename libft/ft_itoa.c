/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:46:08 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/25 19:18:59 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	nbr_len(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	rev_arr(char *arr)
{
	char	tmp;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(arr);
	while (i <= (size / 2))
	{
		tmp = arr[i];
		arr[i] = arr[size - 1];
		arr[size - 1] = tmp;
		i++;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		i;
	int		op;
	int		size;

	i = 0;
	op = 0;
	size = nbr_len(n);
	arr = malloc((size + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (i < size)
	{
		op = n % 10;
		n = n / 10;
		arr[i] = op + '0';
		i++;
	}
	arr[i] = '\0';
	rev_arr(arr);
	return (arr);
}
