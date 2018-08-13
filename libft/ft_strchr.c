/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:53:48 by matranch          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/08/14 00:04:27 by matranch         ###   ########.fr       */
=======
/*   Updated: 2017/12/16 20:55:21 by matranch         ###   ########.fr       */
>>>>>>> 127eae5723e29a25bf760c349cb5b4515e6cf1cd
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i])
	{
		if (str[i] == (char)c)
<<<<<<< HEAD
			return ((char*)s + i + 1);
=======
			return ((char*)s + i);
>>>>>>> 127eae5723e29a25bf760c349cb5b4515e6cf1cd
		i++;
	}
	if ((char)c == '\0')
		return ((char*)s + i);
	return (0);
}
