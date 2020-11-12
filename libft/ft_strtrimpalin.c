/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:47:01 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/15 19:51:15 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimpalin(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		e;
	char	*p;

	i = 0;
	j = 0;
	k = 0;
	while (set[i])
		i++;
	while (s1[j])
		j++;
	e = j;
	p = (char *)malloc((j - 2 * i) * sizeof(char));
	while (k < i && s1[k] == set[k] && s1[j - i] == set[k])
	{
		k++;
		j--;
		if (set[k] == '\0')
			return (p = ft_substr(s1 + i, 0, e - 2 * i));
	}
	return (0);
}
