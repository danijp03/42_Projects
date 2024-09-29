/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:46:08 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/29 22:50:37 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
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
	while (i < (size / 2))
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
		i++;
	}
}

char	*tr_ints(int size, int n, int neg, char *arr)
{
	int	op;
	int	i;
	
	op = 0;
	i = 0;
	if (neg != 0)
		size = size - 1;
	while (i < size)
	{
		op = n % 10;
		n = n / 10;
		arr[i] = op + '0';
		i++;
	}
	if (neg != 0)
			arr[i++] = '-';
	arr[i] = '\0';
	return (arr);
}

char	*last_neg(char *arr)
{
	arr = malloc (12 * sizeof(char));
		arr[0] = '-';
		arr[1] = '2';
		arr[2] = '1';
		arr[3] = '4';
		arr[4] = '7';
		arr[5] = '4';
		arr[6] = '8';
		arr[7] = '3';
		arr[8] = '6';
		arr[9] = '4';
		arr[10] = '8';
		arr[11] = '\0';
		return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;
	int		neg;

	arr = NULL;
	size = nbr_len(n);
	if (n == -2147483648)
	{	
		arr = last_neg(arr);
		return (arr);
	}
	if (n == 0)
	{
		arr = malloc(2 * sizeof(char));
		if (arr == NULL)
			return (NULL);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	arr = malloc((size + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr = tr_ints(size, n, neg, arr);
	rev_arr(arr);
	return (arr);
}
