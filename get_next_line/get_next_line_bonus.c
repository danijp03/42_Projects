get_next_line_bonus.h                                                                               0000644 0307036 0010200 00000002555 14705752142 015466  0                                                                                                    ustar   dajose-p                        2024_madrid                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:26:42 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/22 18:33:28 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
                                                                                                                                                   get_next_line.c                                                                                     0000644 0307036 0010200 00000004160 14705754663 014257  0                                                                                                    ustar   dajose-p                        2024_madrid                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:02:36 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/22 18:58:27 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	leftovers(char **main_line, char **line)
{
	char	*aux;
	int		i;

	i = 0;
	while (main_line[0][i] != '\0' && main_line[0][i] != '\n')
		i++;
	if (main_line[0][i])
		i++;
	*line = ft_substr(*main_line, 0, i);
	if (main_line[0][i])
	{
		aux = ft_substr(*main_line, i, (ft_strlen(*main_line) - i));
		free(*main_line);
		*main_line = aux;
	}
	else
	{
		free(*main_line);
		*main_line = NULL;
	}
}

static char	*cr_main_line(char *main_line, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(main_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free(buffer);
			free(main_line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		main_line = ft_strjoin(main_line, buffer);
		if (!main_line)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (main_line);
}

char	*get_next_line(int fd)
{
	static char	*main_line = NULL;
	char		*line;

	line = NULL;
	if (fd == -1)
		return (NULL);
	main_line = cr_main_line(main_line, fd);
	if (main_line == NULL)
		return (NULL);
	leftovers(&main_line, &line);
	return (line);
}
                                                                                                                                                                                                                                                                                                                                                                                                                get_next_line.h                                                                                     0000644 0307036 0010200 00000002541 14705752142 014253  0                                                                                                    ustar   dajose-p                        2024_madrid                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:26:42 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/21 20:17:33 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
                                                                                                                                                               get_next_line_utils_bonus.c                                                                         0000644 0307036 0010200 00000004574 14705750114 016701  0                                                                                                    ustar   dajose-p                        2024_madrid                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:28:00 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/21 20:28:03 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
                                                                                                                                    get_next_line_utils.c                                                                               0000644 0307036 0010200 00000004574 14705516463 015502  0                                                                                                    ustar   dajose-p                        2024_madrid                                                                                                                                                                                                            /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:28:00 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/21 20:28:03 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	s_len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;
	int		i;
	int		j;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    