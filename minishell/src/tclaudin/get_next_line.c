/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:02:05 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/02 22:18:21 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_next_line(int fd, char **line)
{
	char	*buf;
	char	*line1;
	size_t	size;
	size_t	i;
	ssize_t	fl;

	size = BUFFER_SIZE + 1;
	i = 0;
	if (!(buf = (char*)ft_calloc(2, 1)) ||
	!(line1 = (char*)ft_calloc(size, 1)))
		return (-1);
	while (((fl = read(fd, buf, 1)) > 0 || *line1) && *buf != '\n')
	{
		if (i >= size && !(line1 = ft_remade(line1, &size)))
			return (-1);
		*(line1 + i++) = *buf;
	}
	if (*buf == '\n' || i > 0)
		*line = line1;
	else
		*line = NULL;
	free(buf);
	if (fl == 0)
		return (0);
	return (1);
}
