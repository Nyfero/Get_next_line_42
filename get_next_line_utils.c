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

#include "get_next_line.h"

int	ft_check_new_line(const char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if ((char)buf[i] == '\n')
		   return (i);
		i++;
	}	
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	j;
	char	*strcopie;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	strcopie = (char *)malloc(sizeof(char) * (j + 1));
	if (!strcopie)
		return (NULL);
	i = -1;
	j = 0;
	while (i < (int)(ft_strlen(s1) + ft_strlen(s2)))
	{
		while (++i < (int)ft_strlen(s1))
			strcopie[i] = s1[i];
		while (j < ft_strlen(s2))
			strcopie[i++] = s2[j++];
	}
	strcopie[i] = 0;
	free(s1);
	return (strcopie);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + 1)));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
