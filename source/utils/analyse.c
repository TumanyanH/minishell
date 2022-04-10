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

int	check_built(char *cmd)
{
	return (!ft_strncmp(cmd, "echo\0", 5)
				|| !ft_strncmp(cmd, "cd\0", 3)
				|| !ft_strncmp(cmd, "pwd\0", 4)
				|| !ft_strncmp(cmd, "export\0", 6)
				|| !ft_strncmp(cmd, "unset\0", 6)
				|| !ft_strncmp(cmd, "env\0", 4));
}

int	builtins(int i, char *cmd, char *command)
{
	int		a;
	char	**args;
	int 	j;
	int		fd;

	j = 0;
	fd = 0;
	while (g_val.cmd_table[i].redirects.out[j])
		j++;
	if (i < g_val.cmd_count - 1)
		fd = g_val.pipes[i][1];
	if (j > 0)
		fd = g_val.cmd_table[i].redirects.out[j - 1];
	// j = change_in(i);
	// if (j < 0)
	// 	printf("minishell: no such file or directory\n");
	args = my_split(cmd);
	a = -1;
	if (check_built(command) && j > -1)
	{
		g_val.cmd_table[i].pid = 0;
		if (!ft_strncmp(command, "echo\0", 5))
			a = check_echo(fd, args);
		else if (!ft_strncmp(command, "cd\0", 3))
			a = check_cd(fd, args);
		else if (!ft_strncmp(command, "pwd\0", 4))
			a = check_pwd(fd);
		else if (!ft_strncmp(command, "export\0", 6))
			a = check_export(fd, args);
		else if (!ft_strncmp(command, "unset\0", 6))
			a = check_unset(fd, args);
		else if (!ft_strncmp(command, "env\0", 4))
			a = check_env(fd, args);
		if (i < g_val.cmd_count - 1)
			close(g_val.pipes[i][1]);
		if (i < g_val.cmd_count)
			if (i > 0)
				close(g_val.pipes[i - 1][0]);
		j = 0;
		while (g_val.cmd_table[i].redirects.out[j])
			close(g_val.cmd_table[i].redirects.out[j++]);
		j = 0;
		while (g_val.cmd_table[i].redirects.in[j])
			close(g_val.cmd_table[i].redirects.in[j++]);
		g_val.last_returned = a;
	}
	return (a);
}

void	checking_commands(int i, char *command, char *cmd)
{
	char	**temp;
	char	*acc_check;

	temp = ft_split(g_val.cmd_table[i].cmd, ' ');
	acc_check = ft_access(command);
	if (acc_check)
		ft_exec(i, acc_check);
	else
	{
		printf("minishell: %s: command not found\n", temp[0]);
		exit(127);
	}
}

void	change_in(int i)
{
	int	fd;
	int	j;

	j = 0;
	fd = 0;
	if (i > 0 && i < g_val.cmd_count)
		fd = g_val.pipes[i - 1][0];
	while (g_val.cmd_table[i].redirects.in[j])
		j++;
	if (j > 0)
		fd = g_val.cmd_table[i].redirects.in[j - 1];
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
	// printf("out i=%d, fd = %d\n", i, fd);
	if (fd > 0)
		dup2(fd, 1);
}

void	ft_fork(int i, char *cmd, char *command)
{
	pid_t	pid;
	int		j;
	int		stat;
	int		fd;
	char 	a[20];
	j = 0;

	if (ft_strncmp(command, "exit\0", 5) == 0)
	{
		while (*cmd && !is_space(*cmd))
			cmd++;
		check_exit(cmd);
	}
	else
	{
		command = to_lower(command);
		while (!is_space(*cmd) && *cmd)
			cmd++;
		stat = builtins(i, cmd, command);
		if (stat == -1)
		{
			pid = fork();
			if (pid < 0)
				printf("Error: fork not forked\n");
			else if (!pid)
			{
				change_in(i);
				change_out(i);
				// read(0, a, 20);
				// printf("input %s\n", a);
				// echo barev dzez inchpes eq a+++ | << a cat -e SEGA
				// mi qani heredocov chisht chi shxatum
				checking_commands(i, command, cmd);
			}
			else
			{
				g_val.cmd_table[i].pid = pid;
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
				wait(&stat);
				g_val.last_returned = WEXITSTATUS(stat);
			}
		}
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
			ft_fork(i, cmd, command);
		}
	}
}
