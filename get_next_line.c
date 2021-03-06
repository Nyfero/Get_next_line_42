/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:49:41 by gsap              #+#    #+#             */
/*   Updated: 2021/06/19 17:11:48 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_new_line(char *str, char **line)
{
	int		j;
	int		i;
	char	nw[BUFFER_SIZE];

	i = 0;
	j = 0;
	while (str[i] != '\n')
	{
		nw[i] = str[i];
		i++;
	}
	nw[i] = 0;
	*line = ft_strdup(nw);
	if (!(*line))
		return (-1);
	i++;
	while (str[i])
		str[j++] = str[i++];
	str[j] = 0;
	return (1);
}

int	ft_create_new_line(char **tmp, char *buf, char **line, int i)
{
	buf[i] = 0;
	*line = ft_strjoin(*tmp, buf);
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
	while ((ft_check_new_line(buf) == -1) && rd > 0)
	{
		*tmp = ft_strjoin(*tmp, buf);
		if (!*tmp)
			return (-1);
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = 0;
	}
	if (rd == 0)
		return (ft_last_line(line, buf, tmp));
	return (ft_create_new_line(tmp, buf, line, ft_check_new_line(buf)));
}

int	ft_save_str(char *tmp, char *str, int i)
{
	int	j;

	j = -1;
	if (i == 1)
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
	tmp = NULL;
	if (str[0] != 0)
	{
		if (ft_check_new_line(str) == -1)
		{
			tmp = ft_strdup(str);
			str[0] = 0;
		}
		else
			return (ft_str_new_line(str, line));
	}
	if (!tmp)
		tmp = ft_strdup("");
	if (!tmp)
		return (-1);
	i = ft_read_file(fd, buf, line, &tmp);
	return (ft_save_str(tmp, str, i));
}
