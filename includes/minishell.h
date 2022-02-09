/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:40:33 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/06 16:55:13 by htumanya         ###   ########.fr       */
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
}	g_val;

void	analyse_cmd(char *cmd, char **argv);
void	successful_exit(int a);
void	check_exit(char *cmd);
int		find_env(char **envp);
void	find_path(char **path, char **envp);
void	exit_keypass(void);
void	initial(char **envp);
int		exec_echo( char *cmd );
void	free_2d(char ***arr);
char	*find_cmd_path(char *cmd);

#endif