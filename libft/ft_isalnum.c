/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:41:07 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/15 20:48:56 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalphai(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int		ft_isdigiti(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_isalnum(int c)
{
	if (ft_isalphai(c) || ft_isdigiti(c))
		return (1);
	return (0);
}
