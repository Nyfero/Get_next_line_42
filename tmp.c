/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:53 by gsap              #+#    #+#             */
/*   Updated: 2021/06/14 13:38:45 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			i;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;

	if (fd < 0)
		return (-1);
	if (!str)
		str = ft_strdup("");
	i = ft_check_new_line(str); 
	if (ft_check_new_line(str) > -1)
	{
		str = ft_str_back(i, str, line);
		return (1);
	}
	else
	{
		str = ft_read_line(fd, line, buf, str);
		if (!str)
			return (0);
		return (0);
	}
}

char	*ft_str_back(int i, char *str, char **line)
{
	str[i] = 0;
	*line = ft_strdup(str);
	if (!*line)
		return (NULL);
	str = ft_strdup(&str[i + 1]);
	return (str);
}

char	*ft_read_line(int fd, char **line, char *buf, char *str)
{
	long int	rd;
	int			i;

	rd = read(fd, buf, BUFFER_SIZE);
	while (rd > 0 && ft_check_new_line(buf) < 0)
	{
		buf[rd] = 0;
		str = ft_strjoin(str, buf);
		if (!str)
			return (NULL);
		rd = read(fd, buf, BUFFER_SIZE);
	}
	i = ft_check_new_line(buf);
	if (i < 0)
	{
		str = ft_eof(buf, str, line);
		return (str);
	}
	str = ft_next_line(i, buf, str, line);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_next_line(int i, char *buf, char *str, char **line)
{
	buf[i] = 0;
	str = ft_strjoin(str, buf);
	if (!str)
		return (NULL);
	*line = ft_strdup(str);
	if (!*line)
		return (NULL);
	free(str);
	str = ft_strdup("");;
	str = ft_strjoin(str, &buf[i + 1]);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_eof(char *buf, char *str, char **line)
{
	str = ft_strjoin(str, buf);
	if (!str)
		return (NULL);
	*line = ft_strdup(str);
	if (!*line)
		return (NULL);
	return (str);
}
