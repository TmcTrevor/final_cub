/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:41:43 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/23 13:15:31 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*p;

	t = malloc(sizeof(t_list));
	if (t == NULL)
		return (NULL);
	p = t;
	while (lst != NULL)
	{
		p->content = f(lst->content);
		if (lst->next)
			p->next = malloc(sizeof(t_list));
		else
			p->next = NULL;
		if (p->next == NULL && lst->next != NULL)
		{
			ft_lstclear(&t, del);
			break ;
		}
		p = p->next;
		lst = lst->next;
	}
	return (t);
}
