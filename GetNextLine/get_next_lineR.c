/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:31:31 by matranch          #+#    #+#             */
/*   Updated: 2018/03/09 18:25:53 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				j;
	char			buffer[128];
	char			str[128];
	struct liste	*new;

	*line = NULL;
	i = 0;
	j = 0;
	if (fd < 0)
		return (-1);
	new = malloc(sizeof(liste));
	while ((read(fd, buffer, BUFF_SIZE)) == 0)
	{}
	while(buffer[i])
	{
		if(buffer[i++] == '\n')
		{
			j++;
			break;
		}
	}
	if(j == 0)
		get_rest(fd, buffer, str, new);
	else
		get_line(buffer, str, new, line);
	return (1);
}

void	get_rest(const int fd, char buffer[128], char str[128], struct liste *liste)
{
	int j;
	int k;

	j = 0;
	k = 0;
	if (liste->index == 0)
		liste->index = 0;
	while(buffer[liste->index])
	{
		str[liste->index] = buffer[liste->index];
		liste->index = liste->index + 1;
	}
	while((read(fd, buffer, BUFF_SIZE)) == 0)
	{}
	while(buffer[j])
	{
		str[liste->index] = buffer[j++];
		liste->index = liste->index + 1;
		if(str[liste->index] == '\n')
		{
			k = 1;
			break;
		}
	}
	if (k == 0)
	{
		if(liste->str == NULL)
			liste->str = str;
		else
			liste->str = ft_strcat(liste->str, str);
		get_rest(fd, buffer, str, liste);
	}
	printf("%s", liste->str);
}
void	get_line(char buffer[128], char str[128], struct liste *liste, char **line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (liste->index == 0)
	{
		while (buffer[i] != '\n')
		{
			str[i] = buffer[i];
			i++;
		}
		liste->index = i;
	}
	else
	{
		i = liste->index + 1;
		while (buffer[i] != '\n')
			str[j++] = buffer[i++];
		liste = liste->next;
		liste = malloc(sizeof(liste));
		liste->index = i;
	}
	liste->str = str;
	*line = liste->str;
}
