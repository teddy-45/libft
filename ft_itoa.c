/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesbess <tbesbess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:50:57 by tbesbess          #+#    #+#             */
/*   Updated: 2023/11/18 12:41:41 by tbesbess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_print(int l, char *n_array, int n)
{
	if (n < 0)
	{
		n_array[0] = '-';
		n = -n;
		while (l - 1)
		{
			n_array[--l] = (n % 10) + 48;
			n = n / 10;
		}
	}
	else
	{
		while (l)
		{
			n_array[--l] = (n % 10) + 48;
			n = n / 10;
		}
	}
}

static	int	ft_len(int a)
{
	int	l;

	l = 0; 
	if (a == 0)
		return (1);
	if (a < 0)
	{
		l = 1;
		a = -a;
	}
	while (a != 0)
	{
		a = a / 10;
		l++;
	}
	a = -a;
	return (l);
}

char	*ft_itoa(int n)
{
	char	*n_array;
	size_t	l;

	if (n == 0)
		return (ft_strdup("0"));
	l = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_array = (char *)malloc(sizeof(char) * (l + 1));
	if (!n_array)
		return (NULL);
	n_array[l] = '\0';
	ft_print (l, n_array, n);
	return (n_array);
}
