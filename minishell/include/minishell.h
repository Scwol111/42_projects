/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:59:24 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/08 19:23:20 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"

int			get_next_line(int fd, char **line);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_parse(char *str, t_env_var ***env, t_std_fd *fd);
int			ft_env_find(t_env_var **env, char *str);
int			ft_specials(t_parse *pars, char **str_org, size_t *i, char c);
int			ft_sp_dollar(t_parse *pars, char **str_org, size_t *i);
int			ft_dq_specials(t_parse *pars, char **str_org, size_t *i, char c);
int			ft_sp_slash(t_parse *pars, char **str_org, size_t *i);
int			ft_sp_dquote(t_parse *pars, char **str_org, size_t *i);
int			ft_sp_dots(t_parse *pars, char **str_org, size_t *i);
int			ft_sp_tilda(t_parse *pars, char **str_org, size_t *i);
int			ft_std_tokens(t_parse *pars, size_t n);
int			ft_del_env(t_env_var ***env, char *name);
int			ft_add_env(t_env_var ***env, char *name, char *value);
int			ft_redirects(char **s, t_env_var **e, t_std_fd *now, t_parse *pars);
int			ft_add_redirect(char **s, t_env_var **e, t_std_fd *n, t_parse *p);
int			ft_trc_redirect(char **s, t_env_var **e, t_std_fd *n, t_parse *p);
int			ft_rd_qoutes(char **name, char **str_org, t_size *sz);
int			ft_rd_slash(char **name, char **str_org, t_size *sz);
int			ft_rd_tilda(char **name, char **str, t_size *sz, t_env_var **env);
int			ft_rd_dollar(char **name, char **st_o, t_size *sz, t_env_var **env);
int			ft_inp_redirect(char **s, t_env_var **e, t_std_fd *n, t_parse *p);
int			pipes(t_parse *pars, size_t n);
int			create_echo(t_parse *pars);
int			create_another(t_parse *pars);
int			create_cd(t_parse *pars, size_t n);
int			create_envp(t_parse *pars, size_t n);
int			create_exit(t_parse *pars, size_t n);
int			create_unset(t_parse *pars, size_t n);
int			create_pwd(t_parse *pars, size_t n);
int			create_export(t_parse *pars, size_t n);
int			ft_sp_pipe(t_parse *pars, char **str_org, size_t *i);
int			ft_exit(char **input, t_parse *pars);
int			ft_rd_dquote(char **name, char **str_o, t_size *sz, t_env_var **e);
int			ft_errors_std(int ret, char *err, t_parse *pars);
int			ft_echo(char *str, int flag);
int			ft_errors_exec(char *err, t_parse *pars);
int			ft_errors_redir(char c, char *str, t_parse *pars, short type);
int			save_ret_code(t_parse *pars, size_t n);
int			ft_errors_dp(char *str, t_parse *pars);
int			ft_cd(char *path, t_env_var **env, t_parse *pars);
int			export(t_parse *p, t_env_var ***env, char **input, int e);
int			ft_echo(char *str, int flag);
int			unset(t_parse *pars, t_env_var ***env, char **input);
int			error(int flag, char *comand, t_parse *pars);
int			error_exit(int flag, char *comand, t_parse *pars);

char		*ft_skip_space(char *str);
char		*ft_next_word(char *str);
char		*ft_remade(char *str, size_t *old_size);
char		*ft_remade(char *str, size_t *old_size);
char		**reset_env(t_env_var **envp);

void		destroy_env(t_env_var **env);
void		destroy_args(t_parse *pars, size_t n);
void		ft_reset_fd(t_std_fd *std, t_std_fd *now);
void		destroy_envp(char **env);
void		ft(int sig);
void		ft1(int sig);
void		error_cd(int flag, char *comand, t_parse *pars);
void		error_unset(int flag, char *comand, t_parse *pars);
void		error_export(int flag, char *comand, t_parse *pars);
void		ft_pwd();
void		export_pars(t_parse *pars, int i, int *error_cod, int *flag);

t_parse		ft_reload_parse(t_parse *par);
t_parse		create_pars(t_env_var ***env, t_std_fd *std);
t_parse		*ft_remade_args(t_parse *pars);

t_env_var	**create_env(char **env);

t_std_fd	*copy_std_fd(void);

short		g_flag;
short		g_n;
short		g_cat;

#endif
