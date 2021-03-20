/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:09:11 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:50:23 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

char	*ft_remake(char *str, size_t size)
{
	char *new_str;

	if (!(new_str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(new_str, str, size);
	free(str);
	return (new_str);
}

int		get_next_line(int fd, char **line)
{
	char	*buff;
	char	*line1;
	size_t	size;
	size_t	i;
	ssize_t	fl;

	size = BUFFER_SIZE;
	i = 0;
	if (fd < 0 || !(buff = (char*)ft_calloc(2, 1)) || read(fd, buff, 0) < 0 ||
	BUFFER_SIZE < 1 || !(line1 = (char*)ft_calloc(size, 1)))
		return (-1);
	while ((fl = read(fd, buff, 1)) > 0 && *buff != '\n')
	{
		if (i >= size)
			if (!(line1 = ft_remake(line1, (size += BUFFER_SIZE))))
				return (-1);
		*(line1 + i) = *buff;
		i++;
	}
	*line = line1;
	free(buff);
	if (fl == 0)
		return (0);
	return (1);
}