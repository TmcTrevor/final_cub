/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:28:52 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/23 16:27:17 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int atoi;
	int sign;

	i = 0;
	atoi = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 8 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] > 47 && str[i] < 58)
		atoi = atoi * 10 + str[i++] - '0';
	return (atoi * sign);
}
