/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:56:22 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:26:54 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*str;
	char	*str1;

	str = (char*)s1;
	str1 = (char*)s2;
	i = 0;
	if (!(*s2))
		return ((char*)s1);
	while (*str)
	{
		s1 = str;
		s2 = str1;
		while (*s1 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return (str);
		str++;
	}
	return (NULL);
}
