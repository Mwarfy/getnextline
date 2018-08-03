/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineT.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:17:23 by matranch          #+#    #+#             */
/*   Updated: 2018/08/03 16:10:59 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
		char	*str;
		while(ft_check(str, line) == 0)
		{
			str = ft_strcat(str,  get_read(fd));
		}
		return (0);

}

char 	*get_read(const int fd)
{
	char 	buf[BUFF_SIZE + 1];
	char	*str;
	read(fd, buf, BUFF_SIZE);
	str = ft_strdup(buf);
	return (str);
}

int		ft_check(char *str, char **line)
{
	if(!str)
		return (0);
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
	if(j > 0)
		*line = str2;
	return(j);
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
