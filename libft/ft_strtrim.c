/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:15:58 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:28:18 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	k = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	while (s[j] && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if (i < j)
	{
		if (!(str = malloc(sizeof(char) * (j - i) + 2)))
			return (NULL);
		while ((i <= j) && s[i])
			str[k++] = s[i++];
		str[k] = 0;
		return (str);
	}
	return (ft_strdup(""));
}
