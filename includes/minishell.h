/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:40:33 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/02 20:54:10 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_redirect
{
	int		level;
	char	*path;
}	t_redirect;

typedef struct s_redirects
{
	t_redirect	*in;
	t_redirect	*out;
}	t_redirects;

typedef struct s_commands
{
	int			has_pipe;
	char		*cmd;
	t_redirects	redirects;
}	t_commands;

struct	s_val
{
	int			last_returned;
	int			pipes_count;
	t_list		*env;
	t_commands	*cmd_table;
	int			**pipes;
}	g_val;

void		analyse_cmd(char *cmd, char **argv);
void		successful_exit(int a);
void		check_exit(char *cmd);
void		check_echo(char *cmd);
void		check_pwd(char *cmd);
void		check_cd(char *cmd);
void		check_export(char *cmd);
void		check_unset(char *cmd);
void		check_env(char *cmd);
void		find_path(char **path, char **envp);
void		exit_keypass(void);
void		initial(char **envp);
void		free_2d(char **arr);
char		*find_cmd_path(char *cmd);
void		cmd_not_found(char *cmdname);
void		clear_memory( void );
char		**arg_split(char *str);
char		**ft_split_by_eq(char const *s);
void		export_error(char *cmd);
t_list		*fill_env_list(char **envp);
t_list		*find_env(char *envname);
void		clear_globs( void );
int			check_quotes(char *cmd);

/**
 * @brief parsing
 */
int			check_redirect(char *cmd, int *count);

void		complete_redirects(char **parts);
int			start_parse(char *cmd_line);
void		parse_redirects(char *cmd, int cmd_n);
char		*cpy_till_pipe(char *cmd, int *i);
int			count_pipes(char *cmd, int i);
char		*simplifier(char *cmd);
char		*filter_cmd(char *cmd);
int			check_structure(char *cmd);
void		checking_commands(int i, char *command, char *cmd);
char		**list_to_arr(void);
int			count_env(void);
char		*ft_access(char *command);
void		ft_exec(int i, char *acc_check);
char		**my_split(char *str);

#endif