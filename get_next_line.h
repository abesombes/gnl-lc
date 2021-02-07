/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:15:56 by abesombe          #+#    #+#             */
/*   Updated: 2021/02/07 16:14:04 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct  s_lst t_lst;

struct          s_lst
{
	int		fd;
	char	*str;
	t_lst	*next;
};

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int		ft_char_index(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
t_lst	*ft_lst_add_pushb(t_lst *lst, char *str, int fd);
t_lst	*ft_search_fd(t_lst *lst, int fd);
int		ft_get_line(t_lst *lst_fd, t_lst *cur_fd, char **line, int choice);
t_lst	*ft_lst_add_pushf(t_lst *lst, int buf_size, int fd);
void	ft_strncpy(char *dest, char *src, int start_index, int size);
int		ft_clean_exit(t_lst *lst_fd, t_lst *cur_fd, int rcode);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
