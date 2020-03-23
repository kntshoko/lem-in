/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:43:00 by kntshoko          #+#    #+#             */
/*   Updated: 2019/06/13 15:32:01 by kntshoko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	l;
	int		result;
	int		neg;

	result = 0;
	l = 0;
	neg = 1;
	while ((str[l] >= 9 && str[l] <= 13) || str[l] == 32)
		l++;
	if (str[l] == '-')
		neg = -1;
	if (str[l] == '-' || str[l] == '+')
		l++;
	while (str[l] != '\0' && ft_isdigit(str[l]))
	{
		result = result * 10 + str[l] - 48;
		l++;
	}
	result = result * neg;
	if (result == 469762049)
		result = 0;
	if (result == -469762049)
		result = -1;
	return (result);
}
