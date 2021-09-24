/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:44:55 by ygomes-d          #+#    #+#             */
/*   Updated: 2021/09/24 20:20:43 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*make_next_str(char *str)
{
	char	*next_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	next_str = ft_strdup(str + i);
	free (str);
	return (next_str);
}

static char	*make_line(int fd, char *str, char *buff)
{
	int		r;
	char	*tmp;

	r = 1;
	while (r != 0)
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
		str = ft_strjoin(tmp, buff);
		free (tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free (buff);
	return (str);
}

static char	*cpyline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line[0])
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[MAX_DEFAULT];
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_DEFAULT)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	str[fd] = make_line(fd, str[fd], buff);
	if (!str[fd])
		return (NULL);
	line = cpyline(str[fd]);
	str[fd] = make_next_str(str[fd]);
	return (line);
}
