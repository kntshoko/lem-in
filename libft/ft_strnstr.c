/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:22:00 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/12 17:21:49 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ihay;

	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == 0)
		return (0);
	ihay = ft_strlen(needle);
	while (ihay <= len-- && *haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, ihay) == 0 && *haystack == *needle)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
