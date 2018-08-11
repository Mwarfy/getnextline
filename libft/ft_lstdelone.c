/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:04:09 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 22:34:25 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	(*del)((*alst)->content, (*alst)->content_size);
	tmp = (*alst)->next;
	free(*alst);
	*alst = tmp;
	*alst = NULL;
}
