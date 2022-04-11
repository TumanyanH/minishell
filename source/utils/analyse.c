/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/11 20:39:07 by htumanya         ###   ########.fr       */
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

int	find_builtin(int a, char *command, int fd, char	**args)
{
	if (!ft_strncmp(command, "echo\0", 5))
		a = check_echo(fd, args);
	else if (!ft_strncmp(command, "cd\0", 3) && g_val.cmd_count == 1)
		a = check_cd(fd, args);
	else if (!ft_strncmp(command, "pwd\0", 4))
		a = check_pwd(fd);
	else if (!ft_strncmp(command, "export\0", 6) && g_val.cmd_count == 1)
		a = check_export(fd, args);
	else if (!ft_strncmp(command, "unset\0", 6) && g_val.cmd_count == 1)
		a = check_unset(fd, args);
	else if (!ft_strncmp(command, "env\0", 4))
		a = check_env(fd, args);
	return (a);
}

int	builtins(int i, char *cmd, char *command)
{
	int		a;
	char	**args;
	int		j;
	int		fd;

	j = 0;
	fd = 0;
	while (g_val.cmd_table[i].redirects.out[j])
		j++;
	if (i < g_val.cmd_count - 1)
		fd = g_val.pipes[i][1];
	if (j > 0)
		fd = g_val.cmd_table[i].redirects.out[j - 1];
	args = my_split(cmd);
	a = -1;
	if (check_built(command) && j > -1)
	{
		g_val.cmd_table[i].pid = 0;
		a = find_builtin(a, command, fd, args);
		parental_things(i);
		g_val.last_returned = a;
		return (-2);
	}
	return (a);
}

void	checking_commands(int i, char *command, char *cmd)
{
	char	**temp;
	char	*acc_check;

	temp = my_split(g_val.cmd_table[i].cmd);
	acc_check = ft_access(command);
	if (acc_check)
		ft_exec(i, acc_check);
	else
	{
		printf("minishell: %s: command not found\n", temp[0]);
		exit(127);
	}
}

void	analyse_cmd(char *cmd, char **argv)
{
	int		i;
	char	**command;
	int		stat;

	if (cmd && ft_strlen(cmd) > 0)
	{
		start_parse(cmd);
		i = -1;
		while (++i < g_val.cmd_count)
		{
			cmd = ft_strtrim(g_val.cmd_table[i].cmd, " ");
			command = my_split(cmd);
			ft_fork(i, cmd, command[0]);
		}
	}
}
