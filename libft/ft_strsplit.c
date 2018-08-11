/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:23:19 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:28:27 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(ptr = malloc(sizeof(char*) * ft_nombre((char*)s, 1, c, 0) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[j] = ft_memalloc(ft_nombre((char*)s, 2, c, j) + 1);
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (((char)s[i] != c) && ((char)s[i] != '\0'))
				ptr[j][k++] = (char)s[i++];
			ptr[j++][k] = 0;
			k = 0;
		}
	}
	ptr[j] = 0;
	return (ptr);
}
