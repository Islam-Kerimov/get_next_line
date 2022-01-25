/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:24:12 by ctanton           #+#    #+#             */
/*   Updated: 2020/12/30 14:54:57 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc((size + 1) * sizeof(*tmp))))
		return (NULL);
	tmp[size] = '\0';
	while (size--)
		tmp[size] = '\0';
	return (tmp);
}

static char		*ft_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (remainder[i] != '\n')
		i++;
	if (!(tmp = (char *)malloc((i + 1) * sizeof(*tmp))))
		return (NULL);
	j = 0;
	while (i > 0)
	{
		tmp[j] = remainder[j];
		j++;
		i--;
	}
	tmp[j] = '\0';
	return (tmp);
}

static char		*ft_gnl(char **line, char *remainder, char *buf)
{
	char	*p;

	if ((p = ft_strchr(remainder, '\n')) != 0)
	{
		*line = ft_remainder(remainder);
		p = ft_strdup(++p);
	}
	else
		*line = ft_strdup(remainder);
	free(remainder);
	free(buf);
	return (p);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rem;
	int			l_b;
	char		*p;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, NULL, 0)) < 0 ||
			!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	l_b = 1;
	rem == NULL ? rem = ft_strnew(0) : NULL;
	while (!(ft_strchr(rem, '\n')) && (l_b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[l_b] = '\0';
		p = ft_strjoin(rem, buf);
		free(rem);
		rem = p;
	}
	if ((l_b != 0) || (rem != 0))
	{
		p = ft_gnl(line, rem, buf);
		rem = p;
	}
	else if (l_b == -1)
		return (-1);
	return (l_b != 0 ? 1 : 0);
}
