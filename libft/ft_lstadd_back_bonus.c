/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:15:13 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/22 16:33:24 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *t;

	t = *alst;
	if (*alst == 0)
	{
		*alst = new;
		new->next = NULL;
	}
	else
	{
		while (t->next)
			t = t->next;
		t->next = new;
		new->next = NULL;
	}
}
