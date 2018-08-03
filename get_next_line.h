/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:29:39 by matranch          #+#    #+#             */
/*   Updated: 2018/08/03 16:08:03 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define BUFF_SIZE 20

static struct 		liste
{
	char 					*str;
	int						index;
	struct liste			*next;
}							liste;

int		get_next_line(const int fd, char **line);
void		get_rest(const int fd, char buffer[128], char str[128], struct liste *liste);
void		get_line(char buffer[128], char str[128], struct liste *liste, char **line);
char	*ft_strccpy(char *dest, const char *src, size_t n, size_t n2);
char	*ft_strcchr(const char *src, int c);
int		ft_check(char *str, char **line);
char	*get_read(const int fd);
#endif
