/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 17:05:01 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/12 11:54:27 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			l;

	l = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (l < n)
	{
		if (ss1[l] != ss2[l])
			return (ss1[l] - ss2[l]);
		l++;
	}
	return (0);
}
