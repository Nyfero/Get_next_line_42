#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(int fd, char **ligne);
int		str_new_line(char *str, char **line, int i);
int		buf_new_line(char *str, char *buf, char **line, int i);
int		ft_read_file(int fd, char *buf, char **line, char *str);
int		ft_last_line(char *str, char **line);
//char	*ft_read_line(int fd, char **line, char *buf, char *str);
//char	*ft_eof(char *buf, char *str, char **line);
//char	*ft_next_line(int i, char *buf, char *str, char **line);
//char	*ft_str_back(int i, char *str, char **line);
int		ft_check_new_line(const char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif
