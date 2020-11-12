/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:23:32 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/24 22:29:18 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*src_1;
	unsigned char		*dest_1;

	i = 0;
	src_1 = (unsigned char *)src;
	dest_1 = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (0);
	if (dest_1 == src_1)
		return (src_1);
	while (i < n)
	{
		dest_1[i] = src_1[i];
		i++;
	}
	return (dest);
}
