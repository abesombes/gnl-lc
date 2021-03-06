/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:17:29 by abesombe          #+#    #+#             */
/*   Updated: 2021/02/08 18:23:32 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_clean_exit(t_lst *lst_fd, int rcode)
{
	t_lst *tmp;

	while (lst_fd->next)
	{
		tmp = lst_fd;
		lst_fd = lst_fd->next;
		free(tmp);
	}
	return (rcode);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*jstr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = (s1 ? ft_strlen(s1) : 0);
	size_s2 = (s2 ? ft_strlen(s2) : 0);
	if (!(jstr = (char *)malloc(size_s1 + size_s2 + 1)))
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
		{
			jstr[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (s2[j])
			jstr[i++] = s2[j++];
	jstr[i] = '\0';
	return (jstr);
}

void	ft_strncpy(char *dest, char *src, int start_index, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[start_index + i];
		i++;
	}
	dest[i] = '\0';
}

int		get_next_line(int fd, char **line)
{
	static t_lst	*lst_fd;
	t_lst			*cur_fd;
	int				ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(lst_fd = ft_lst_add_push(lst_fd, -2, BUFFER_SIZE)))
		return (-1);
	if ((cur_fd = ft_search_fd(lst_fd, fd)))
		if (ft_char_index(cur_fd->str, '\n') >= 0)
			if (ft_get_line(cur_fd, line, 1))
				return (1);
	while ((ret = read(fd, lst_fd->str, BUFFER_SIZE)) > 0)
	{
		(lst_fd->str)[ret] = '\0';
		if (!cur_fd)
			if (!(cur_fd = ft_lst_add_push(lst_fd, fd, -1)))
				return (-1);
		if (ft_merge_into_line(lst_fd, cur_fd, line))
			return (1);
	}
	if (ret < 0)
		return (-1);
	return (ft_get_line(cur_fd, line, 2));
}

int main(int ac, char **av)
{
    int ret;
    int fd1;
    int fd2;
    char *line;
	(void)ac;
   // int i=0;

    fd1 = open(av[1], O_RDONLY);
    fd2 = open(av[2], O_RDONLY);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 0, line, ret, fd1);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 0, line, ret, fd2);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 1, line, ret, fd2);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 1, line, ret, fd1);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 2, line, ret, fd1);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 3, line, ret, fd1);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 4, line, ret, fd1);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 2, line, ret, fd2);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 3, line, ret, fd2);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 5, line, ret, fd1);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 6, line, ret, fd1);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 4, line, ret, fd2);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 5, line, ret, fd2);
	free(line);
	ret = get_next_line(fd1, &line);
	printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", 7, line, ret, fd1);
	free(line);

   /* while ((ret = get_next_line(fd1, &line)) > 0)
    {
        i++;
 		printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", i, line, ret, fd1);
	  //  free(line);
    }
	printf("%s    %d   %d\n", line, ret, fd);*/
	//free(line);
    return (0);
}
