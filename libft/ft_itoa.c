/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:08:35 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/24 15:53:39 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_digits(long n)
{
	int i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		j;
	int		flag;
	long	n2;

	i = 0;
	flag = 0;
	n2 = n;
	j = n_digits(n2);
	if (!(p = (char *)malloc((j + 1) * sizeof(char))))
		return (0);
	if (n2 < 0)
	{
		flag = 1;
		p[0] = '-';
		n2 *= -1;
	}
	p[j] = '\0';
	while (j-- > flag)
	{
		p[j] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (p);
}
