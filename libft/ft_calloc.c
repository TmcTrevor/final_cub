/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:53:44 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/22 04:01:11 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_bzerox(void *p, size_t n)
{
	size_t		i;
	char		*s;

	i = 0;
	s = (char *)p;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
	return (p);
}

void			*ft_calloc(size_t count, size_t size)
{
	void	*p;
	int		i;

	i = 0;
	if (!(p = malloc(count * size)))
		return (0);
	ft_bzerox(p, count * size);
	return (p);
}
