/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:44:55 by ygomes-d          #+#    #+#             */
/*   Updated: 2021/09/23 10:07:43 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char *make_line(int fd, char *str, char *buff)
{
	int		r;
	char	*tmp;

	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[r] = '\0';
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(str, buff);
		free (tmp);
		if (ft_strchr(str, '\n'))
			break;
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char *str;
	char *buff;
	char *line;
	int	i;
	char *temp;

	i = 0;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = make_line(fd, str, buff);
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i++] == '\n')
	{
		line = ft_substr(str, 0, i);
		temp = str;
		str = ft_strdup(str + i);
		free (temp);
	}
	else
		line = ft_strdup(str);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
