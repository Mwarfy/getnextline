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
	}
	if (ret == 0)
		ret = ft_read(fd, str, &rest[fd], line);
	if (ret == 0 && (ft_strlen(*line) > 0))
		return (1);
	if (ret < 0)
		return (-1);
	return (ret > 0 ? 1 : 0);
}

int		ft_read(const int fd, char *str, char **rest, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
		if ((*rest = ft_strchr(ft_strdup(buf), '\n')))
			break ;
	}
	ft_check(str, line);
	return (ret);
}

int		ft_check(char *str, char **line)
{
	int		i;
	int		ret;
	char	*str1;

	ret = 0;
	str1 = ft_strnew(0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			ret = 1;
			break;
		}
		str1[i] = str[i];			
	}
	str1[i] = 0;
	*line = str1;
	return (ret);
}

/*int 	main(void)
{
	char *line;
	int out;
	int p[2];
	char *str;
	int len = 50;
	int fd;
	int i;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while(len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	close(p[0]);
	fd = open("test", O_WRONLY);
	write(fd, str, strlen(str));
	close(fd);
	fd = open("test1", O_WRONLY);
	write(fd, line, ft_strlen(line));
	close(fd);
	i = strcmp(line, str);
	printf("%d", i);
	return (0);
}*/
