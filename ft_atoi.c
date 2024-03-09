/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesbess <tbesbess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:34:11 by tbesbess          #+#    #+#             */
/*   Updated: 2023/11/13 18:17:31 by tbesbess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	r;
	long	tmpr;

	sign = 1;
	r = 0;
	tmpr = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = sign * (-1);
	}
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + (*str++ - 48);
		if (tmpr > r && sign == -1)
			return (0);
		if (tmpr > r && sign == 1)
			return (-1);
		tmpr = r;
	}
	return (r * sign);
}
