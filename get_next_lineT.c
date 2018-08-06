/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineT.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:17:23 by matranch          #+#    #+#             */
/*   Updated: 2018/08/06 17:24:02 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int STATUS = 1;

int		get_next_line(const int fd, char **line)
{
		static char	*str;
		int		i;
		if(!(*line))
		{
			*line = malloc(sizeof(1));
			str = malloc(sizeof(1));
		}
		str = get_read(fd, line);
		return (0);
}

char 	*get_read(const int fd, char **line)
{
	char 	buf[BUFF_SIZE + 1];
	char	*str;
	int     i;

	while(i == 0)
	{
		read(fd, buf, BUFF_SIZE);
		str = ft_strdup(buf);
		i = ft_check(str, line);
	}
	str = *line;
	return (str);
}

int		ft_check(char *str, char **line)
{
	int i;
	int j;
	char *str2;

	str2 = malloc(sizeof(1));
	j = 0;
	i = -1;
	while(str[++i])
	{
		if(str[i] == '\n')
		{
			j++;
			break;
		}
		str2[i] = str[i];
	}
	*line = ft_strcat(*line, str2);
	return(j);
}

void	increment_read(const int fd, char *str)
{
	char	buf[2];
	int 	i;
	i = ft_strlen(str);
	while((i--) > 0)
	{
		read(fd, buf, 1);
	}
}

int 	main(int ac, char **av)
{
	char *line;

	/*get_next_line(open(av[1], O_RDONLY), &line);
	printf("%s", line);*/
		get_next_line(open(av[1], O_RDONLY), &line);
		printf("%s", line);
	get_next_line(open(av[1], O_RDONLY), &line);
		printf("%s", line);
}
