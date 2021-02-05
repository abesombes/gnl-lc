/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:17:29 by abesombe          #+#    #+#             */
/*   Updated: 2021/02/05 23:59:25 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char 			*buf;
	int				ret;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if ((cur_fd = ft_search_fd(lst_fd, fd)))
		if (ft_char_index(cur_fd->str, '\n') >= 0)
			if (ft_get_line(lst_fd, cur_fd, line, 1))
				return (1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	lst_fd = ft_lst_add_pushf(lst_fd, buf, -2);
	while ((ret = read(fd, lst_fd->str, BUFFER_SIZE)) > 0)
	{
	//	printf("\nret: [%i]", ret);
		(lst_fd->str)[ret] = '\0';

		if (ret > 0)
		{
			if (!cur_fd)
				cur_fd = ft_lst_add_pushb(lst_fd, NULL, fd);
			if (ft_get_line(lst_fd, cur_fd, line, 0))
				return (1);
		}
	}
//	printf("\nret: [%i] - fd: [%i] - lst_fd->str: [%s]", ret, fd, lst_fd->str);
	//printf("\nFIN DU FICHIER - EOF");
	return (0);
}

int main(int ac, char **av)
{
    int ret;
    int fd;
    char *line;
	(void)ac;
    int i=0;

    fd = open(av[1], O_RDONLY);

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        i++;
 		printf("\n[line %d] - line = [%s] - ret: [%d] - fd: [%d]\n", i, line, ret, fd);
	   // free(line);
    }
	printf("%s    %d   %d\n", line, ret, fd);
//	free(line);
    return (0);
}
