/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:44:09 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 21:09:20 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	int		i;

	i = 0;
	if ((src = malloc(sizeof(char) * ft_strlen(s) + 1)) != NULL)
	{
		while (s[i] != '\0')
		{
			src[i] = s[i];
			i++;
		}
		src[i] = 0;
		return (src);
	}
	else
		return (0);
}
