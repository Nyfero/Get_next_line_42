/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:49:41 by gsap              #+#    #+#             */
/*   Updated: 2021/06/20 14:04:51 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_stat_new_line(char *stat, char **line)
{
	int		compt_stat;
	int		reset_stat;
	char	new_line[BUFFER_SIZE];

	compt_stat = 0;
	reset_stat = 0;
	while (stat[compt_stat] != '\n')
	{
		new_line[compt_stat] = stat[compt_stat];
		compt_stat++;
	}
	new_line[compt_stat] = 0;
	*line = ft_strdup(new_line);
	if (!(*line))
		return (-1);
	compt_stat++;
	while (stat[compt_stat])
		stat[reset_stat++] = stat[compt_stat++];
	stat[reset_stat] = 0;
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

int	ft_save_stat(char *tmp, char *stat, int ret_read)
{
	int	compt;

	compt = -1;
	if (ret_read == 1)
	{
		while (tmp[++compt])
			stat[compt] = tmp[compt];
		stat[compt] = 0;
		free(tmp);
	}
	return (ret_read);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	stat[2048][BUFFER_SIZE];
	char		*tmp;
	int			ret_read;

	if (BUFFER_SIZE < 1 || (read(fd, buf, 0) == -1))
		return (-1);
	tmp = NULL;
	if (stat[fd][0])
	{
		if (ft_check_new_line(stat[fd]) > -1)
			return (ft_stat_new_line(stat[fd], line));
		else
		{
			tmp = ft_strdup(stat[fd]);
			stat[fd][0] = 0;
		}
	}
	if (!tmp)
		tmp = ft_strdup("");
	if (!tmp)
		return (-1);
	ret_read = ft_read_file(fd, buf, line, &tmp);
	return (ft_save_stat(tmp, stat[fd], ret_read));
}
