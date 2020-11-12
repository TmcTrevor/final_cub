/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:06:09 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/21 17:30:39 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*e;

	i = 0;
	e = (char *)s;
	while (e[i])
		i++;
	while (i && e[i] != (char)c)
		i--;
	if (e[i] == (char)c)
		return (e + i);
	else
		return (0);
}
