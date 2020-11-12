/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:21:33 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/22 16:34:23 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *t;
	t_list *p;

	t = *lst;
	if (t)
		while (t)
		{
			p = t->next;
			del(t->content);
			free(t);
			t = p;
		}
	*lst = NULL;
}
