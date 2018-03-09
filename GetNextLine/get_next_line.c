/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 08:14:14 by matranch          #+#    #+#             */
/*   Updated: 2018/03/09 19:10:34 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char 		*past;
	char		buf[BUFF_SIZE + 100];
	char 		*line_r;
	static int 	i;
	int 		j;

	if(fd < 0)
		return (-1);
	if(i)
		j = i;
	else
		j = 0;
	while ((read(fd, buf, BUFF_SIZE)))
	{
		line_r = ft_strchr(buf, '\n');
		if (line_r)
		{
			while(buf[i])
			{
				if(buf[i] == '\n')
					break;
				i++;
			}
			i++;
			past = ft_strnew((size_t)i - (size_t)j);
			ft_strccpy(past, buf, (size_t)j, (size_t)i);
		}
	}
	*line = past;
	printf("%s", *line);
	return (1);
}

char	*ft_strccpy(char *dest, const char *src, size_t n, size_t n2)
{
	int i;

	i = 0;
	while(n < n2)
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	return(dest);
}

int main(int ac, char **av)
{
	char *line;
	int i = 0;
	while(i < 2)
	{
		get_next_line(open(av[1], O_RDONLY), &line);
		i++;
	}
}
