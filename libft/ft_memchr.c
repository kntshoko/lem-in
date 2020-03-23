/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:14:15 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/24 10:09:37 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	size_t			l;

	if (!s && !n)
		return (NULL);
	l = 0;
	ss = (unsigned char *)s;
	while (n--)
	{
		if (ss[l] == (unsigned char)c)
			return ((void *)&ss[l]);
		l++;
	}
	return (NULL);
}
