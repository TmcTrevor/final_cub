/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:37:13 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/15 13:03:44 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	i = -1;
	j = 0;
	p = (char *)str;
	if (to_find[j] == '\0')
		return (p);
	while (p[++i] != '\0')
	{
		if (p[i] == to_find[0])
		{
			k = i + 1;
			j = 1;
			while (to_find[j] != '\0' && to_find[j] == p[k++])
				j++;
			if (to_find[j] == '\0')
				return (p + i);
		}
	}
	return (0);
}
