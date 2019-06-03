/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:47:10 by bscussel          #+#    #+#             */
/*   Updated: 2019/05/30 16:04:18 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		strdiv(char **str, char **line, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	if (str[fd][len] == '\n' || str[fd][len] == '\0')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				red;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	static char		*str[255];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(red);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (buff[red - 1] == '\0')
			break ;
	}
	if (red < 0)
		return (-1);
	else if (red == 0 && str[fd] == NULL)
		return (0);
	return (strdiv(str, line, fd));
}
