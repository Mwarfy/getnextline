/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:47:16 by matranch          #+#    #+#             */
/*   Updated: 2017/12/14 18:11:40 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		i = 0;
		while (s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (0);
}
