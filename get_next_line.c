/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:49:41 by gsap              #+#    #+#             */
/*   Updated: 2021/06/17 11:12:20 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_new_line(char *str, char **line)
{
	int		j;
	int		i;
	char	*nw;

	nw = NULL;
	i = -1;
	j = 0;
	while (str[++i] != '\n')
		nw[i] = str[i];
	nw[i] = 0;
	i++;
	while (str[i])
		str[j++] = str[i++];
	str[j] = 0;
	*line = ft_strdup(nw);
	if (!(*line))
		return (-1);
	return (1);
}

int	buf_new_line(char **tmp, char *buf, char **line, int i)
{
	buf[i] = 0;
	*tmp = ft_strjoin(*tmp, buf);
	if (!*tmp)
		return (-1);
	*line = ft_strdup(*tmp);
	free(*tmp);
	if (!(*line))
		return (-1);
	*tmp = ft_strdup(&buf[i + 1]);
	if (!*tmp)
	{
		free(*line);
		return (-1);
	}
	return (1);
}

int	ft_read_file(int fd, char *buf, char **line, char **tmp)
{
	long int	rd;

	rd = read(fd, buf, BUFFER_SIZE);
	buf[rd] = 0;
	while (rd > 0 && (ft_check_new_line(buf) == -1))
	{
		*tmp = ft_strjoin(*tmp, buf);
		if (!*tmp)
			return (-1);
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = 0;
	}
	if (rd < BUFFER_SIZE)
	{
		buf[rd] = 0;
		*tmp = ft_strjoin(*tmp, buf);
		*line = *tmp;
		if (!(*line))
			return (-1);
		return (0);
	}
	return (buf_new_line(tmp, buf, line, ft_check_new_line(buf)));
}

int	ft_last_ft(char *tmp, char *str, int i, char **line)
{
	int	j;

	j = -1;
	if (i == -1)
	{
		free(*line);
		free(tmp);
		return (-1);
	}
	if (i != 0)
	{
		while (tmp[++j])
			str[j] = tmp[j];
		str[j] = 0;
		free(tmp);
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	static char	str[BUFFER_SIZE];

	if (BUFFER_SIZE < 1 || (read(fd, buf, 0) == -1))
		return (-1);
	printf("1\n");
	tmp = NULL;
	if (str[0] != 0)
	{
		i = 0;
		if (ft_check_new_line(str) == -1)
		{
			tmp = ft_strdup(str);
			while (str[i])
				str[i++] = 0;
		}
		else
			return (str_new_line(str, line));
	}
	if (!tmp)
		tmp = ft_strdup("");
	if (!tmp)
		return (-1);
	i = ft_read_file(fd, buf, line, &tmp);
	return (ft_last_ft(tmp, str, i, line));
}
