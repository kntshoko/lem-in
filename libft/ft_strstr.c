/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:11:25 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/13 14:11:37 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t in;

	in = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (*needle == '\0')
		return (0);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, in) == 0 && *haystack == *needle)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
