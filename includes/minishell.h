/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:40:33 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/27 22:06:03 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>

typedef struct s_redirect
{
	int		level;
	char	*path;
} t_redirect;

typedef struct s_redirects
{
	t_redirect in;
	t_redirect out;
} s_redirects;

struct	s_val
{
	char	*path;
	t_list	*env;
	int		last_returned;
	s_redirects redirects;
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
t_env_item	*find_env(t_list *env, char *envname);

/**
 * @brief parsing
 */
int	check_redirect(char *cmd);
void	complete_redirects(char **parts);


#endif