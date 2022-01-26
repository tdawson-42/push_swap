/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:55:56 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/20 19:36:33 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define BUFF_SIZE 32
#define MAX_FD 4096

static int	add_to_line(char **stat, char **line)
{
	int		len;
	char	*tmp;

	len = ft_strlenc(*stat, '\n');
	if (len < 0)
	{
		*line = ft_strdup(*stat);
		ft_strdel(stat);
	}
	else
	{
		*line = ft_strsub(*stat, 0, len);
		tmp = ft_strdup(&((*stat)[len + 1]));
		ft_strdel(stat);
		*stat = tmp;
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stat[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (line == NULL || (fd < 0 || fd > MAX_FD) || read(fd, buf, 0) < 0)
		return (-1);
	if (!stat[fd])
		stat[fd] = ft_strnew(0);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		stat[fd] = ft_strjoinf(stat[fd], buf, 1);
		if ((ft_strchr(buf, '\n')))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && stat[fd][0] == '\0')
	{
		ft_strdel(stat);
		return (0);
	}
	return (add_to_line(&stat[fd], &*line));
}
