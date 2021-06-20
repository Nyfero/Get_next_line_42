/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:30:05 by gsap              #+#    #+#             */
/*	 Updated: 2021/06/12 11:20:00 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_last_line(char **line, char *buf, char **tmp)
{
	int	index_new_line;

	index_new_line = ft_check_new_line(buf);
	if (index_new_line != -1)
		buf[index_new_line] = 0;
	*line = ft_strjoin(*tmp, buf);
	if (!(*line))
		return (-1);
	return (0);
}

int	ft_check_new_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		compt;
	char	*strcopie;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strcopie = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strcopie)
		return (NULL);
	compt = -1;
	while (++compt < len_s1)
		strcopie[compt] = s1[compt];
	while ((compt - len_s1) < len_s2)
	{
		strcopie[compt] = s2[(compt - len_s1)];
		compt++;
	}
	strcopie[compt] = 0;
	free(s1);
	return (strcopie);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	compt;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	compt = 0;
	while (s1[compt])
	{
		dest[compt] = s1[compt];
		compt++;
	}
	dest[compt] = 0;
	return (dest);
}
