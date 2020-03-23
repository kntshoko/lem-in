/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:03:28 by kntshoko          #+#    #+#             */
/*   Updated: 2019/07/06 04:33:29 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_wrdcnt(char const *s, int c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			l++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (l);
}

static	size_t	ft_chrcnt(char const *s, int c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		l++;
		i++;
	}
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	row;
	size_t	i;
	char	**str;

	row = 0;
	i = 0;
	if (!s || (!(str = (char **)malloc(sizeof(char *) * \
						(ft_wrdcnt(s, c) + 1)))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			str[row] = ft_strsub(s, i, ft_chrcnt(&s[i], c));
			row++;
			i = i + ft_chrcnt(&s[i], c);
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	str[ft_wrdcnt(s, c)] = NULL;
	return (str);
}
