#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **ligne);
int		ft_stat_new_line(char *stat, char **line);
int		ft_create_new_line(char **tmp, char *buf, char **line, int index_new_line);
int		ft_read_file(int fd, char *buf, char **line, char **tmp);
int		ft_save_stat(char *tmp, char *stat, int ret_read);
int		ft_last_line(char **line, char *buf, char **tmp);
int		ft_check_new_line(char *s);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif
