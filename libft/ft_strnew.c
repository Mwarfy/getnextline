/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:05:25 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 20:53:16 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = NULL;
	i = 0;
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(str, '\0', (size + 1));
	return (str);
}
