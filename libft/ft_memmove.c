/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:03:54 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/12 11:51:26 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	l;

	l = 0;
	s = (char *)src;
	d = (char *)dst;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else if (dst == NULL && src == NULL)
		return (NULL);
	else if (len <= 0)
		return (dst);
	else
		while (len--)
			d[len + l] = s[l + len];
	return (dst);
}
