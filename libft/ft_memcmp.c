/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:52:32 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 19:20:30 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	if (n > 65535)
		return (0);
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && ((i + 1) < n))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
