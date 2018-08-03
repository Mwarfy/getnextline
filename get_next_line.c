/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 08:14:14 by matranch          #+#    #+#             */
/*   Updated: 2018/04/18 14:20:56 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char static		*rest;
	char			*tmp;
	char			*tmp2;
	int				ret;

	if(!*line)
	{
		rest = malloc(sizeof(1));
		*line = malloc(sizeof(1));
		tmp = malloc(sizeof(1));
	}
	tmp = ft_strdup(rest);
	//printf("TMP : %s", tmp);
	if((rest = ft_check(tmp)))
	{
	//	printf("REST : %s", rest);
		tmp2 = ft_strnew((int)ft_strlen(tmp) - (int)ft_strlen(rest) - 1);
		*line = ft_strncpy(tmp2, tmp, (int)ft_strlen(tmp) - (int)ft_strlen(rest) - 1);
		return (1);
	}
	else
	{
	/*	if(ft_strlen(tmp) > 0)
		{
			*line = tmp;
			return (1);
		}*/
		printf("TEST");
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if((rest = ft_strchr(ft_strdup(buf), '\n')))
			{
			//	printf("REST NUMERO 1 : %s", rest);
				tmp2 = ft_strnew((int)ft_strlen(buf) - (int)ft_strlen(rest) - 1);
				*line = ft_strjoin(*line, ft_strncpy(tmp2, buf, (int)ft_strlen(buf) - (int)ft_strlen(rest) - 1));
				return (1);
			}
			else
				*line = ft_strjoin(*line, ft_strdup(buf));
		/*i += ret;
		if(i > k)
		{
			if((rest = ft_strchr(ft_strdup(buf), '\n')))
			{
				k = i;
				tmp = ft_strnew((int)ft_strlen(buf) - (int)ft_strlen(rest) - 1);
				ft_strncpy(tmp, buf, (int)ft_strlen(buf) - (int)ft_strlen(rest) - 1);
				*line = ft_strjoin(*line, tmp);
				return (1);
			}
			else
				*line = ft_strjoin(*line, ft_strdup(buf));
		}*/
		}
		
	}
	return (0);
}

char*	ft_check(char *rest)
{
	char *tmp;

	tmp = rest;
	if(ft_strlen(tmp) > 0)
	{
	//	printf("CHECK TMP BEFORE %s", tmp);
		tmp = ft_strchr(rest, '\n');
	//	printf("CHECK TMP AFTER %s", tmp);
		if(ft_strlen(tmp) > 0)
			return (tmp);
	}
	return (0);
}

int main(int ac, char **av)
{
	char *line;
	int i;

	/*get_next_line(open(av[1], O_RDONLY), &line);
	printf("%s\n", line);
	get_next_line(open(av[1], O_RDONLY), &line);
	printf("%s\n", line);
	get_next_line(open(av[1], O_RDONLY), &line);
	printf("%s\n", line);
	get_next_line(open(av[1], O_RDONLY), &line);
	printf("%s\n", line);*/
	while((i = get_next_line(open(av[1], O_RDONLY), &line)) != 0 ){
		printf("%s\n", line);
		printf("%d\n", i);
	}
	return (0);
}
