/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:51:16 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/04 11:43:57 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_line(int fd, char **str, char **line)
{
	char	*hold;
	int		i;

	i = 0;
	if (str[fd][0] == '\0')
		return (0);
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		hold = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = hold;
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

static int	ft_read(const int fd, char **str)
{
	char	*hold;
	int		rd;
	char	buff[BUFF_SIZE + 1];

	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		hold = ft_strjoin(str[fd], buff);
		ft_strdel(&str[fd]);
		str[fd] = hold;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (rd);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[1025];
	int			rd;

	if (fd < 0 || fd >= 1025 || line == NULL || read(fd, str[fd], 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	if ((ft_strchr(str[fd], '\n')))
		return (ft_line(fd, str, line));
	rd = ft_read(fd, str);
	if (rd < 0)
		return (-1);
	return (ft_line(fd, str, line));
}
