/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:43:45 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/17 19:39:54 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memset(char *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	ch;

	ch = c;
	i = 0;
	while (i < n && s[i] != '\0')
	{
		s[i] = c;
		i++;
	}
	while (s[i] != '\0')
		i++;
	s[i] = '\0';
	return (s);
}