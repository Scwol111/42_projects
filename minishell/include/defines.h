/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:21:57 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/13 13:16:18 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <limits.h>
# include "structs.h"
# include "errors.h"
# include "../libft/libft.h"

# define BUFFER_SIZE 128
# define SPECIALS " \\\"\'$;|~><"
# define D_SPECIALS "$\\"
# define DQ_SHILD "\\\"$"
# define RD_SPECIALS "\\\'\"$~"
# define RD_OUT " ;|"
# define NAME "lotcshell-v1.5$ "
# define SKIP_NAME "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"
# define SPACE_NAME "                "
# define DOLLAR_END " \\\"\'$;|~></#=.,:^%+`"

#endif
