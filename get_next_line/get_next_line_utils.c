/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:33:45 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/05/21 14:33:46 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len = ft_strlen(s);
	char	*copy = (char *)malloc(len + 1);
	size_t	i = 0;
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i = 0;
	size_t	slen = ft_strlen(s);
	char	*sub;

	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static void	cpy(char *dst, const char *src, size_t n)
{
	while (n--)
		*dst++ = *src++;
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*new = (char *)malloc(len1 + len2 + 1);
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	cpy(new, s1, len1);
	cpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	free(s1);
	return (new);
}
