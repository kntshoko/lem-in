/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:34:39 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/24 09:41:10 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	st;
	size_t	e;
	size_t	l;
	size_t	n;

	if (s == NULL)
		return (NULL);
	st = 0;
	e = ft_strlen(s) - 1;
	while ((s[st] == 32 || s[st] == '\t' || s[st] == '\n') && (s[st] != '\0'))
		st++;
	if (s[st] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	while (s[e] == 32 || s[e] == '\t' || s[e] == '\n')
		e--;
	l = 2 + e - st;
	n = 2 + e - st;
	if (!(str = (char *)malloc(sizeof(char) * l)))
		return (NULL);
	ft_memset(str, '\0', n);
	ft_memmove(str, s + st, l - 1);
	return (str);
}
