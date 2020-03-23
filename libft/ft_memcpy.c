/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:08:00 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/12 11:48:18 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (n < 1)
		return (dst);
	else if (dst == NULL && src == NULL)
		return (dst);
	else if (dst == 0 && src == 0)
		return (NULL);
	else
		while (n--)
		{
			*(d++) = (*s++);
		}
	return (dst);
}
