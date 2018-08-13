/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:47:55 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:26:13 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char*)src;
	str2 = (char*)dest;
	if (n > 65535)
		return (NULL);
	if (str1 < str2)
		while (n--)
			str2[n] = str1[n];
	else
	{
		if (n > 0)
			ft_memcpy(str2, str1, n);
	}
	return (str2);
}
