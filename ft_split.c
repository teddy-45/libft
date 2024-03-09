/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbesbess <tbesbess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:32:22 by tbesbess          #+#    #+#             */
/*   Updated: 2023/11/14 17:35:11 by tbesbess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static	size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static	char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static	void	*free2darray(char **array, int n)
{
	while (n--)
		free(array[n]);
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**r;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	r = (char **)malloc(sizeof(char *) * (count + 1));
	if (!r)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		r[i] = malloc(sizeof (char) * (word_len(s, c) + 1));
		if (!r[i])
			return (free2darray(r, i));
		ft_strncpy(r[i], s, word_len(s, c));
		r[i++][word_len(s, c)] = '\0';
		s = s + word_len(s, c);
	}
	r[i] = NULL;
	return (r);
}
