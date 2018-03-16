/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 08:14:14 by matranch          #+#    #+#             */
/*   Updated: 2018/03/16 19:59:23 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *past;
	char 		*line_r;
	char		*tmp;
	int 		i;

	if(!(*line))
		*line = malloc(sizeof(*line));
	while ((read(fd, buf, BUFF_SIZE)))
	{
		past = ft_strdup(buf);
		line_r = ft_strchr(past, '\n');
		if(line_r)
		{
			i = line_r - past;
			tmp = ft_strnew(i);
			tmp = ft_strncpy(tmp, past, (size_t)i);
			*line = ft_strjoin(*line, tmp);
		}
		else
			*line = ft_strjoin(*line, past);
	}
	printf("%s", *line);
	return (1);
}

int main(int ac, char **av)
{
	char *line;
	int i = 0;
	get_next_line(open(av[1], O_RDONLY), &line);
	//while((get_next_line(open(av[1], O_RDONLY), &line) == 0)){}
	return (0);
}
