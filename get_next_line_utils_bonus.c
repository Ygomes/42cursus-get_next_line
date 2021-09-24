/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:44:59 by ygomes-d          #+#    #+#             */
/*   Updated: 2021/09/24 12:20:56 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	compare;

	str = (char *)s;
	compare = (unsigned char)c;
	while (*str)
	{
		if (*str == compare)
			return (str);
		str++;
	}
	if (!compare && !*str)
		return (str);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dups;

	dups = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!dups)
		return (NULL);
	while (s[i])
	{
		dups[i] = s[i];
		i++;
	}
	dups[i] = '\0';
	return (dups);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	size;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (s[i + j] && j < len)
	{
		substr[j] = s[i + j];
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*str;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	while (lens1--)
		str[lens1] = s1[lens1];
	lens1 = ft_strlen(s1);
	while (lens2--)
		str[lens1 + lens2] = s2[lens2];
	lens2 = ft_strlen(s2);
	str[lens1 + lens2] = '\0';
	return (str);
}
