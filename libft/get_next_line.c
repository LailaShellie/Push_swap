/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:36:37 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/25 11:36:41 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int		parse_line(char **fd_stack, char **line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	if (!*fd_stack)
		return (0);
	tmp = *fd_stack;
	while (tmp[i] != '\n')
		if (tmp[i++] == 0)
			return (0);
	tmp[i] = 0;
	*fd_stack = ft_strdup(&tmp[i + 1]);
	*line = ft_strdup(tmp);
	free(tmp);
	return (1);
}

static int		read_file(const int fd, char *buf, char **fd_stack, char **line)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (*fd_stack == 0)
			*fd_stack = ft_strdup(buf);
		else if (*fd_stack != 0)
		{
			tmp = *fd_stack;
			*fd_stack = ft_strjoin(*fd_stack, buf);
			free(tmp);
			tmp = 0;
		}
		if (parse_line(fd_stack, line) == 1)
			return (1);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (*fd_stack && *fd_stack[0] != 0 && ft_strchr(*fd_stack, '\n') == 0)
	{
		*line = *fd_stack;
		*fd_stack = 0;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*fd_stack[MAX_FD];
	char			*buf;
	int				num;

	buf = 0;
	if (fd < 0 || fd >= MAX_FD)
		return (-1);
	if (parse_line(&fd_stack[fd], line) == 1)
		return (1);
	if (!(buf = (char *)malloc(BUFF_SIZE + 1)) || (read(fd, buf, 0)) < 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	num = read_file(fd, buf, &fd_stack[fd], line);
	free(buf);
	buf = 0;
	return (num);
}
