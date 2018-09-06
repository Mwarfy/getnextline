/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:29:39 by matranch          #+#    #+#             */
/*   Updated: 2018/09/06 18:37:12 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <string.h>
# include <regex.h>
# include <assert.h>

# define BUFF_SIZE 5

int		get_next_line(const int fd, char **line);
int		ft_check(char *str, char **line);
int		ft_read(const int fd, char *str, char **rest, char **line);
#endif
