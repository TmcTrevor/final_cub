/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:16:58 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/23 19:35:10 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		trim_left(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

static	int		trim_right(char const *s1, char const *set, int c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	i--;
	while (i > c)
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j++;
		if (set[j] == '\0')
			return (i);
		i--;
	}
	return (c + 1);
}

static char		*ft_void(void)
{
	char *a;

	a = (char *)malloc(sizeof(char));
	a[0] = '\0';
	return (a);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 || !set)
		return (0);
	i = trim_left(s1, set);
	if (i != -1)
		j = trim_right(s1, set, i);
	else
		return (p = ft_void());
	return (p = ft_substr(s1, i, j - i + 1));
}
