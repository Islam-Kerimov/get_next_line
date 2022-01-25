/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:59:44 by ctanton           #+#    #+#             */
/*   Updated: 2020/12/30 14:21:16 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		j;
	int		i;
	char	*new_s1;

	i = 0;
	while (s1[i] != '\0')
		i++;
	new_s1 = (char *)malloc((i + 1) * sizeof(*new_s1));
	if (new_s1 == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		new_s1[j] = s1[j];
		j++;
	}
	new_s1[j] = '\0';
	return (new_s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		k;

	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	k = 0;
	while (*s1 != '\0')
	{
		dst[k] = *s1++;
		k++;
	}
	while (*s2 != '\0')
	{
		dst[k] = *s2++;
		k++;
	}
	dst[k] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}
