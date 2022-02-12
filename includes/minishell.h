/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:40:33 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/12 21:12:57 by htumanya         ###   ########.fr       */
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

struct	s_val
{
	char	*path;
	char	**envp;
	t_list	*env;
}	g_val;

void	analyse_cmd(char *cmd, char **argv);
void	successful_exit(int a);
void	check_exit(char *cmd);
void	check_echo(char *cmd);
void	check_pwd(char *cmd);
void	check_cd(char *cmd);
void	check_export(char *cmd);
void	check_unset(char *cmd);
void	check_env(char *cmd);
int		find_env(char **envp, char *envname);
void	find_path(char **path, char **envp);
void	exit_keypass(void);
void	initial(char **envp);
void	free_2d(char **arr);
char	*find_cmd_path(char *cmd);
void	cmd_not_found(char *cmdname);
void	clear_memory( void );
t_list	*fill_env_list(char **envp);

#endif