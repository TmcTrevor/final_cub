/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:26:30 by mokhames          #+#    #+#             */
/*   Updated: 2019/10/13 12:49:24 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ucheck(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		lcheck(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ncheck(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		not_lun(char c)
{
	if (ucheck(c) == 1 || lcheck(c) == 1 || ncheck(c) == 1)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (lcheck(*str) == 1)
		*str -= 32;
	while (str[i] != '\0')
	{
		if (not_lun(str[i - 1]) == 1 && ucheck(str[i]) == 1)
			str[i] += 32;
		if (not_lun(str[i]) == 0 && lcheck(str[i + 1]) == 1)
			str[i + 1] -= 32;
		i++;
	}
	return (str);
}
