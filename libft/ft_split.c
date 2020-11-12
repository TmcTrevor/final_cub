/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:54:55 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/23 19:34:38 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		skip(const char *s, char c, int *t)
{
	int i;

	i = 0;
	*t = 1;
	while (s[i] == c && s[i] != 0)
		i++;
	return (i);
}

static char		*ft_taballoc(int *i, const char *str, char c, int *t)
{
	int		j;
	int		e;
	char	*p;

	j = 0;
	e = 0;
	*t = 0;
	while (str[j] != c && str[j])
		j++;
	*i = *i + j;
	p = (char *)malloc((j + 1) * sizeof(char));
	if (!p)
		return (0);
	while (j)
	{
		p[e] = str[e];
		e++;
		j--;
	}
	p[e] = '\0';
	return (p);
}

static char		**ft_free_str(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

static char		**help(const char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!(tab = (char**)malloc(sizeof(char*))))
		return (NULL);
	if (!(tab[0] = (char*)malloc(1 * strlen(str) + 1)))
		return (ft_free_str(tab, 2));
	while (str[i])
	{
		tab[0][i] = str[i];
		i++;
	}
	tab[0] = NULL;
	return (tab);
}

char			**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		sp;
	int		o;

	j = 0;
	i = 0;
	sp = 1;
	if (!(str))
		return (NULL);
	o = ft_word_count(str, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (o + 1))) || o == -1)
		return (o == -1 ? help(str) : NULL);
	while (j < o)
	{
		if (sp && str[i] != c &&
				(!(tab[j++] = ft_taballoc(&i, &str[i], c, &sp))))
			return (ft_free_str(tab, j));
		else
			i += skip(&str[i], c, &sp);
	}
	tab[j] = NULL;
	return (tab);
}
