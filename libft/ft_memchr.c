/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:50:44 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 19:18:46 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n > 65535)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char*)s)[i] != ((unsigned char)c))
			i++;
		else
			return ((void*)(s + i));
	}
	return (0);
}
