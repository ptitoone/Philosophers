/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:17 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:17 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_ribool	ft_gnl_status(int eof, const char *file, char *line)
{
	if (eof == -1)
	{
		ft_free_char(&line);
		return (ft_error("program has failed to read in the file :\n", file));
	}
	return (T_TRUE);
}

int	ft_gnl_return_value(t_buffer *buff)
{
	if ((buff->buffinc) == (buff->readlen) && (buff->readlen) < BUFFER_SIZE)
	{
		(buff->buffinc) = 0;
		return (0);
	}
	else if ((buff->buffer)[(buff->buffinc)] == '\n')
	{
		(buff->buffinc)++;
		return (1);
	}
	return (2);
}

int	ft_gnl_line_maker(t_buffer *buff, ssize_t *linelen, char **line)
{
	char			*delline;
	ssize_t			mallinc;

	mallinc = 0;
	while (buff->buffer[buff->buffinc + mallinc] != '\n'
		&& (buff->buffinc + mallinc) < buff->readlen)
		mallinc++;
	if (*linelen)
		delline = *line;
	*line = malloc((*linelen) + mallinc + 1);
	if (!(*line))
		return (-1);
	if (*linelen > 0)
	{
		*linelen = -1;
		while (delline[++(*linelen)])
			(*line)[(*linelen)] = delline[(*linelen)];
		free(delline);
	}
	while (buff->buffer[buff->buffinc] != '\n' && buff->buffinc < buff->readlen)
		(*line)[(*linelen)++] = buff->buffer[buff->buffinc++];
	(*line)[(*linelen)] = '\0';
	return ((ft_gnl_return_value(buff)));
}

int	get_next_line(int fd, char **line)
{
	static t_buffer		buff[256];
	ssize_t				linelen;
	int					rtnval;

	linelen = 0;
	rtnval = 2;
	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 255) || !line)
		return (-1);
	while (rtnval == 2)
	{
		if (buff[fd].buffinc == buff[fd].readlen)
			buff[fd].buffinc = 0;
		if (!buff[fd].buffinc)
		{
			buff[fd].readlen = read(fd, buff[fd].buffer, BUFFER_SIZE);
			if (buff[fd].readlen == -1)
			{
				buff[fd].readlen = 0;
				return (-1);
			}
		}
		rtnval = ft_gnl_line_maker(&(buff[fd]), &linelen, line);
	}
	return (rtnval);
}
