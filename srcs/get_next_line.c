/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:47:49 by plehtika          #+#    #+#             */
/*   Updated: 2022/03/18 11:29:13 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	copy_line(char **line, char *remain, char **buf)
{
	int	i;

	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	*line = (char *)malloc(i + 1);
	if (!(*line))
	{
		ft_strdel(buf);
		return (-1);
	}
	ft_strncpy(*line, remain, i);
	(*line)[i] = '\0';
	ft_strdel(buf);
	if (remain[i] == '\n')
		ft_strcpy(remain, &remain[i + 1]);
	else
		ft_strclr(remain);
	return (1);
}

static int	read_until_newline(const int fd, char **remain, char **line)
{
	long int	read_bytes;
	char		*buf;

	buf = (char *)malloc(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	if (ft_strchr(*remain, '\n') != NULL)
		return (copy_line(line, *remain, &buf));
	read_bytes = read(fd, buf, BUFF_SIZE);
	while (read_bytes != 0 || **remain != '\0')
	{
		if (read_bytes == -1)
			break ;
		buf[read_bytes] = '\0';
		*remain = ft_strstretch(remain, buf);
		if (ft_strchr(*remain, '\n') != NULL)
			return (copy_line(line, *remain, &buf));
		else if (read_bytes < BUFF_SIZE)
			return (copy_line(line, *remain, &buf));
		read_bytes = read(fd, buf, BUFF_SIZE);
	}
	ft_strdel(&buf);
	if (read_bytes == -1)
		return (-1);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*remain[MAX_FD];
	int			return_value;

	if (fd < 0 || fd > MAX_FD - 1 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!remain[fd])
		remain[fd] = ft_strnew(0);
	if (!remain[fd])
		return (-1);
	return_value = read_until_newline(fd, &remain[fd], line);
	if (return_value <= 0)
		ft_strdel(&(remain[fd]));
	return (return_value);
}
