/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:18:52 by jvictor-          #+#    #+#             */
/*   Updated: 2021/07/09 19:14:15 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	unsigned char	*allocated;
	size_t				i;

	total_size = size * nmemb;
	allocated = (unsigned char *)malloc(total_size);
	i = 0;
	if (allocated == 0)
		return (NULL);
	while (i < size)
	{
		allocated[i] = '\0';
		i++;
	}
	return (allocated);
}

int	ft_strchr_GNL(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (HAVNT_BRK_LINE);
	while (s[i])
	{
		if (s[i] == c)
			return (HAV_BRK_LINE);
		i++;
	}
	if (s[i] == c)
		return (HAV_BRK_LINE);
	return (HAVNT_BRK_LINE);
}

size_t	ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		substr = (char *)ft_calloc(sizeof(char), 1);
		if (!substr)
			return (NULL);
		return (substr);
	}
	if (len > ft_strlen(s + start))
		substr = (char *)ft_calloc(sizeof(char), (ft_strlen(s + start)) + 1);
	else
		substr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!substr)
		return (NULL);
	while (i++ < len)
		substr[i] = s[i + start];
	return (substr);
}
