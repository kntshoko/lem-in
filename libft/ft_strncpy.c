/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:43:26 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/12 16:35:57 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t l;

	l = 0;
	while (src[l] != '\0' && l < n)
	{
		dst[l] = src[l];
		l++;
	}
	while (l < n)
	{
		dst[l] = '\0';
		l++;
	}
	return (dst);
}
