/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:33:10 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/14 17:00:01 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || !(str = ft_strnew(len)))
		return (NULL);
	ft_memset(str, '\0', len);
	ft_strncpy(str, s + start, len);
	return ((char *)str);
}
