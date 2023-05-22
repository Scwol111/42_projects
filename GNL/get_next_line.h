/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita <nikita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:09:09 by nikita            #+#    #+#             */
/*   Updated: 2020/06/20 18:58:41 by nikita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_remake(char *str, size_t size);
void	*ft_calloc(size_t number, size_t size);

#endif
