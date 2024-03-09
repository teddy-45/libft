/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesbess <tbesbess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:51:26 by tbesbess          #+#    #+#             */
/*   Updated: 2023/11/14 12:50:18 by tbesbess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == 0 && needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		j = 0;
		i = 0;
		while (haystack[i] == needle[i] && haystack[i] && needle[i] && i < len)
		{
			if (!needle[j + 1])
				return ((char *)haystack);
			i++;
			j++; 
		}
		haystack++;
		len--;
	}
	return (NULL);
}
