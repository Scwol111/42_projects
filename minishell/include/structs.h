/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:47:19 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/01 15:32:03 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	unsigned char	t_uchar;
typedef long long		t_llong;

typedef struct			s_this_is_enviromental_varables
{
	char	*name;
	char	*value;
}						t_env_var;

typedef struct			s_standart_file_descriptor
{
	int fd_zero;
	int	fd_one;
}						t_std_fd;

typedef struct			s_this_is_arguments_for_pars_yes_i_can_write_long_name
{
	char		**arg;
	size_t		*size;
	size_t		*cur_size;
	size_t		sz;
	int			dquo;
	int			quo;
	int			ret_code;
	char		fl;
	t_std_fd	*std_fd;
	t_env_var	**env;
	t_env_var	***envp;
	t_std_fd	now_fd;
	short		pipe;
}						t_parse;

typedef struct			s_this_is_just_size_t_but_doubled
{
	size_t size;
	size_t curr;
}						t_size;

typedef struct			s_this_is_double_int_variables
{
	int x;
	int	y;
}						t_dint;

#endif
