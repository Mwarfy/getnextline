/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:53:19 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:28:06 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = ft_strdup("");
	i = 0;
	if (len > 0 && s)
	{
		if (!(str = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = 0;
	}
	return (str);
}
