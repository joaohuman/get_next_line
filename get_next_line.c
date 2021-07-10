/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:18:39 by jvictor-          #+#    #+#             */
/*   Updated: 2021/07/09 20:35:34 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	read_and_join(int fd, char **buf_of_read,
						char **buf_of_line, int *bytes)
{
	char	*temporary_of_read;

	while (*bytes && ft_strchr_GNL(*buf_of_line, '\n') == HAVNT_BRK_LINE)
	{
		*bytes = read(fd, *buf_of_line, BUFFER_SIZE);
		(*buf_of_line)[*bytes] = '\0';
		if (*bytes < 0 || *bytes > BUFFER_SIZE)
		{
			free(*buf_of_line);
			return (GNL_ERROR);
		}
		temporary_of_read = *buf_of_read;
		*buf_of_read = ft_strjoin(temporary_of_read, *buf_of_line);
		free(temporary_of_read);
	}
	free(*buf_of_line);
	return (READ_AND_JOINED_OR_EOF);
}

char	*make_line_and_buf_of_read(char **line, char *buf_of_read, int bytes)
{
	int		position_of_brkline;
	int		len_of_buf_of_read;
	char	*new_buf_of_read;

	position_of_brkline = 0;
	len_of_buf_of_read = 0;
	new_buf_of_read = NULL;
	while (buf_of_read[position_of_brkline] != '\n'
		&& buf_of_read[position_of_brkline])
		position_of_brkline++;
	*line = ft_substr(buf_of_read, 0, position_of_brkline);
	if (!(**line))
		return (NULL);
	if (bytes)
	{
		if (buf_of_read[position_of_brkline] == '\n')
			position_of_brkline++;
		len_of_buf_of_read = ft_strlen(buf_of_read + position_of_brkline);
		new_buf_of_read = ft_substr(buf_of_read, position_of_brkline,
				len_of_buf_of_read);
		if (!new_buf_of_read)
			return (NULL);
	}
	free(buf_of_read);
	return (new_buf_of_read);
}

int	get_next_line(int fd, char **line)
{
	static char		*buf_of_read;
	char			*buf_of_line;
	int				bytes;
	int				verification;

	bytes = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > MAX_FILE_DESCRIPTOR)
		return (GNL_ERROR);
	if (!buf_of_read)
	{
		buf_of_read = (char *)ft_calloc(1, 1);
		if (!buf_of_read)
			return (GNL_ERROR);
	}
	buf_of_line = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf_of_line)
		return (GNL_ERROR);
	verification = read_and_join(fd, &buf_of_read, &buf_of_line, &bytes);
	if (verification == GNL_ERROR)
		return (GNL_ERROR);
	buf_of_read = make_line_and_buf_of_read(line, buf_of_read, bytes);
	if (!bytes)
		return (GNL_FOUND_EOF);
	return (GNL_SUCCESSFULL);
}
