/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:52:35 by gsap              #+#    #+#             */
/*   Updated: 2021/06/14 14:52:50 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	*line;
	int	gnl;
	int 	i = 1;

	fd = open("test.txt", O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("ligne %d -->%s\n", i, line);
		free(line);
		i++;
	}
	return (0);
}
