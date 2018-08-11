/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:25:56 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:27:05 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = NULL;
	if (size > 65535)
		return (NULL);
	if (size > 0)
	{
		if (!(mem = malloc(size)))
			return (NULL);
		ft_memset(mem, 0, size);
	}
	return (mem);
}
