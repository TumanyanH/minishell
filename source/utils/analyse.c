/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 21:15:19 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtins(char *cmd, char *command)
{
	int		a;
	char	**args;

	a = 1;
	args = my_split(cmd);
	if (!ft_strncmp(command, "echo\0", 5))
		check_echo(args);
	else if (!ft_strncmp(command, "cd\0", 3))
		check_cd(args);
	else if (!ft_strncmp(command, "pwd\0", 4))
		check_pwd(args);
	else if (!ft_strncmp(command, "export\0", 6))
		check_export(args);
	else if (!ft_strncmp(command, "unset\0", 6))
		check_unset(args);
	else if (!ft_strncmp(command, "env\0", 4))
		check_env(args);
	else
		a = 0;
	return (a);
}

void	checking_commands(int i, char *command, char *cmd)
{
	char	**temp;
	char	*acc_check;

	command = to_lower(command);
	temp = ft_split(cmd, ' ');
	while (!is_space(*cmd) && *cmd)
		cmd++;
	if (!builtins(cmd, command))
	{
		acc_check = ft_access(command);
		if (acc_check)
			ft_exec(i, acc_check);
		else
		{
			printf("minishell: %s: command not found\n", temp[0]);
			exit(127);
		}
	}
}

void	change_in(int i)
{
	int	fd;
	int	j;

	j = 0;
	fd = 0;
	if (i < g_val.cmd_count)
		if (i > 0)
			fd = g_val.pipes[i - 1][0];
	while (g_val.cmd_table[i].redirects.in[j])
		j++;
	if (i > 0 && i < g_val.cmd_count - 1)
		fd = g_val.pipes[i][0];
	if (j > 0)
		fd = g_val.cmd_table[i].redirects.in[j - 1];
	printf("%d\n", fd);
	if (fd > 0)
		dup2(fd, 0);
}

void	change_out(int i)
{
	int	fd;
	int	j;

	j = 0;
	fd = 0;
	while (g_val.cmd_table[i].redirects.out[j])
		j++;
	if (i < g_val.cmd_count - 1)
		fd = g_val.pipes[i][1];
	if (j > 0)
	{
		fd = g_val.cmd_table[i].redirects.out[j - 1];
		// if (i > 0 && i < g_val.cmd_count - 1)
		// 	write(g_val.pipes[i - 1][1], "\0", 1);
		// else if (i == 0 && i < g_val.cmd_count - 1)
		// 	write(g_val.pipes[0][1], "\0", 1);
		// chem porcel bayc piti vor esel ashxati
	}
	if (fd > 0)
		dup2(fd, 1);
}

void	ft_fork(int i, char *cmd, char *command)
{
	pid_t	pid;
	int		j;

	j = 0;
	pid = fork();
	if (pid < 0)
		printf("Error: fork not forked\n");
	else if (!pid)
	{
		// if (i < g_val.cmd_count)
		// 	if (i > 0)
		// 		dup2(g_val.pipes[i - 1][0], 0);
		change_in(i);
		change_out(i);
		checking_commands(i, command, cmd);
	}
	else
	{
		if (i < g_val.cmd_count - 1)
			close(g_val.pipes[i][1]);
		if (i < g_val.cmd_count)
			if (i > 0)
				close(g_val.pipes[i - 1][0]);
		while (g_val.cmd_table[i].redirects.out[j])
			close(g_val.cmd_table[i].redirects.out[j++]);
		j = 0;
		while (g_val.cmd_table[i].redirects.in[j])
			close(g_val.cmd_table[i].redirects.in[j++]);
	}
}

void	analyse_cmd(char *cmd, char **argv)
{
	int		i;
	char	*command;
	int		stat;

	if (cmd && ft_strlen(cmd) > 0)
	{
		start_parse(cmd);
		i = -1;
		while (++i < g_val.cmd_count)
		{
			cmd = ft_strtrim(g_val.cmd_table[i].cmd, " ");
			command = quote_skip(cmd);
			if (cmd && ft_strncmp(command, "exit\0", 5) == 0)
			{
				while (*cmd && !is_space(*cmd))
					cmd++;
				check_exit(cmd);
			}
			ft_fork(i, cmd, command);
		}
		i = -1;
		while (++i < g_val.cmd_count)
		{
			wait(&stat);
			g_val.last_returned = WEXITSTATUS(stat);
		}
		// clear_globs();
	}
}
