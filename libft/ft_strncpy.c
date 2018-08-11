/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:47:26 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 20:53:38 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (i < n)
	{
		if (src[j] == '\0')
		{
			dest[i] = 0;
			i++;
		}
		else
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	return (dest);
}
