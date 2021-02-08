/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:15:56 by abesombe          #+#    #+#             */
/*   Updated: 2021/02/08 18:18:52 by abesombe         ###   ########.fr       */
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
	char	*tmp;
	char	*tmp2;
	t_lst	*next;
};

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int		ft_char_index(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
t_lst	*ft_lst_add_push(t_lst *lst, int fd, int bs);
t_lst	*ft_search_fd(t_lst *lst, int fd);
int		ft_get_line(t_lst *cur_fd, char **line, int choice);
int		ft_merge_into_line(t_lst *lst_fd, t_lst *cur_fd, char **line);
void	ft_strncpy(char *dest, char *src, int start_index, int size);
int		ft_clean_exit(t_lst *lst_fd, int rcode);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
