/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:37:12 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/22 16:32:12 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (0);
	else
	{
		new_element->content = content;
		new_element->next = NULL;
	}
	return (new_element);
}
