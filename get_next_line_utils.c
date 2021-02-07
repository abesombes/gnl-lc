/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:17:00 by abesombe          #+#    #+#             */
/*   Updated: 2021/02/07 17:03:17 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_char_index(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == c)
			return (i);
		s++;
		i++;
	}
	if (*s == c)
		return (i);
	return (-1);
}

t_lst	*ft_search_fd(t_lst *lst, int fd)
{
	t_lst *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

t_lst	*ft_lst_add_pushb(t_lst *lst, char *str, int fd)
{
	t_lst	*new_elem;
	t_lst	*tmp;

	tmp = lst;
	if (!(new_elem=(t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	new_elem->str = str;
	new_elem->fd = fd;
	new_elem->next = NULL;
	tmp->next = new_elem;
	return (new_elem);
}

t_lst	*ft_lst_add_pushf(t_lst *lst, int buf_size, int fd)
{
	t_lst	*new_elem;
	char	*buf;

	if (!(new_elem = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (buf_size + 1))))
		return (NULL);
	new_elem->str = buf;
	new_elem->fd = fd;
	new_elem->next = lst;
	return (new_elem);
}

int		ft_get_line(t_lst *lst_fd, t_lst *cur_fd, char **line, int choice)
{
	int i;
	char *tmp;
	if (choice == 2)
	{
		*line = malloc(ft_strlen(cur_fd->str));
		ft_strncpy(*line, cur_fd->str, 0, ft_strlen(cur_fd->str));
		free(cur_fd->str);
		return (0);
	}
	else if (choice == 1)
	{
		i = ft_char_index(cur_fd->str, '\n');
		*line = malloc(i);
		ft_strncpy(*line, cur_fd->str, 0, i);
		tmp = malloc(ft_strlen(cur_fd->str) - i);
		ft_strncpy(tmp, cur_fd->str, i + 1, ft_strlen(cur_fd->str) - i - 1);
		free(cur_fd->str);
		cur_fd->str = tmp;
		return (1);
	}
	else if (choice == 0)
	{
		if ((i = ft_char_index(lst_fd->str, '\n')) >= 0)
		{
		tmp = malloc(i + 1);
		ft_strncpy(tmp, lst_fd->str, 0, i);
		*line = ft_strjoin(cur_fd->str, tmp);
		free(tmp);
		free(cur_fd->str);
		cur_fd->str = malloc(ft_strlen(lst_fd->str) - i - 1);
		ft_strncpy(cur_fd->str, lst_fd->str, i + 1, ft_strlen(lst_fd->str) - i - 1);
		free(lst_fd->str);
		return (1);
		}
		else
		{
			tmp = ft_strjoin(cur_fd->str, lst_fd->str);
			free(cur_fd->str);
			cur_fd->str = malloc(ft_strlen(tmp) + 1);
			ft_strncpy(cur_fd->str, tmp, 0, ft_strlen(tmp));
			free(tmp);
		}
	}
	return (0);
}
