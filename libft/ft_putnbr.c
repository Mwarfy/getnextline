/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:11:56 by matranch          #+#    #+#             */
/*   Updated: 2017/12/16 21:32:55 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_condition(void)
{
	int		i;
	char	*a;

	i = 0;
	a = "2147483648";
	ft_putchar('-');
	while (a[i] != '\0')
	{
		ft_putchar(a[i]);
		i++;
	}
}

void			ft_putnbr(int n)
{
	if (n == (-2147483648))
		ft_condition();
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
