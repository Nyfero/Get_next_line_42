/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:49:41 by gsap              #+#    #+#             */
/*   Updated: 2021/06/15 09:50:10 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_new_line(char *str, char **line, int i)
{
	char *tmp;

	tmp = ft_strdup(str);
	free(str);
	if (!tmp)
	{
		free(*line);
		return (-1);
	}
	if (tmp[i + 1])
		str = ft_strdup(&tmp[i + 1]);
	free(tmp);
	if (!str)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

int	buf_new_line(char *str, char *buf, char **line, int i)
{
	buf[i] = 0;
	str = ft_strjoin(str, buf);
	if (!str)
		return (-1);
	*line = ft_strdup(str);
	if (!(*line))
		return (-1);
	free(str);
	str = ft_strdup(&buf[i + 1]);
	if (!str)
		return (-1);
	free(buf);
	return (1);
}

int	ft_last_line(char *str, char **line)
{
	if (!str)
		return (-1);
	*line = ft_strdup(str);
	if (!(*line))
		return (-1);
	free(str);
	return (0);
}

int	ft_read_file(int fd, char *buf, char **line, char *str)
{
	int			i;
	long int	rd;

	rd = read(fd, buf, BUFFER_SIZE);
	buf[rd] = 0;
	while (ft_check_new_line(buf) == -1)
	{
		buf[rd] = 0;
		str = ft_strjoin(str, buf);
		if (rd == 0)
			return (ft_last_line(str, line));
		rd = read(fd, buf, BUFFER_SIZE);
	}
	i = ft_check_new_line(buf);
	buf = ft_strdup(buf);
	return (buf_new_line(str, buf, line, i));
}

int	get_next_line(int fd, char **line)
{
	int			i;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;

	if (BUFFER_SIZE < 0 || (read(fd, buf, 0) == -1))
		return (-1);
	if (!str)
		str = ft_strdup("");
	if (!str)
		return (-1);
	if (line)
		free(line);
	if (!line)
		line = (char **)malloc(sizeof(char) * 2);
	*line = ft_strdup("");
	i = ft_check_new_line(str);
	if (i == -1)
		return (ft_read_file(fd, buf, line, str));
	str[i] = 0;
	*line = ft_strdup(str);
	if (!(*line))
	{
		free(str);
		return (-1);
	}
	return (str_new_line(str, line, i));
}
