/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:25:31 by matranch          #+#    #+#             */
/*   Updated: 2018/09/06 18:41:51 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*rest[255];
	char			*str;
	int			ret;
	
	if (!line || fd < 0)
		return (-1);
	ret = 0;
	*line = NULL;
	str = ft_strnew(0);
	if (rest[fd])
	{
		str = ft_strdup(rest[fd]);
		if (ft_check(str, line))
		{
			rest[fd] = ft_strchr(rest[fd], '\n');
			ret++;
		}
		else
			rest[fd] = NULL;
	}
	if (ret == 0)
		ret = ft_read(fd, str, &rest[fd], line);
	if (ret < 0)
		return (-1);
	return (ret > 0 ? 1 : 0);
}

int		ft_read(const int fd, char *str, char **rest, char **line)
{
	int		ret;
	char		*tmp;
	char	buf[BUFF_SIZE + 1];
	
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (str)
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
		else
			str = ft_strdup(buf);
		if ((*rest = ft_strchr(str, '\n')))
			break ;
	}
	ft_check(str, line);
	if (ft_strlen(str))
		ret = 1;
	return (ret);
}

int		ft_check(char *str, char **line)
{
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			ret = 1;
			break ;
		}
	}
	str[i] = 0;
	*line = str;
	return (ret);
}
