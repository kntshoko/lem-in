/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:59:36 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/13 14:47:16 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t n;
	size_t l;
	size_t sl;

	l = ft_strlen(dst);
	sl = ft_strlen(src);
	n = 0;
	if (dstsize <= l)
		return (dstsize + sl);
	dstsize--;
	while ((dst[n] != '\0') && n < dstsize)
		n++;
	while (dstsize > n && *src)
	{
		dst[n] = *src;
		src++;
		n++;
	}
	dst[n] = '\0';
	return (sl + l);
}
