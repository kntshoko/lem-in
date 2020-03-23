/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:20:54 by kntshoko          #+#    #+#             */
/*   Updated: 2019/09/04 11:44:59 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t l;

	l = 0;
	while (s[l] != '\0' && s[l] == (unsigned char)c)
		l++;
	if (s[l] == (unsigned char)c)
		return ((char *)&s[l]);
	return (0);
}
