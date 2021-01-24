/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <mokhames@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:36:35 by mokhames          #+#    #+#             */
/*   Updated: 2021/01/24 19:26:15 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char  *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	p = (char *)malloc((i + j + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strcpy(p, s1);
	ft_strcpy(p + i, s2);
	p[i + j] = '\0';
	return (p);
}
