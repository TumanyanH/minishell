/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:49:14 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/14 21:08:18 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parental_things(int i)
{
	int	stat;
	int	j;

	j = 0;
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

int	is_bash(char *cmd)
{
	int		i;
	int		ret;
	char	**split;

	i = 0;
	ret = 0;
	split = ft_split(cmd, '/');
	while (split[i])
	{
		if (!ft_strncmp(split[i], "minishell", ft_strlen(split[i])))
		{
			ret = 1;
			free(split[i]);
			break ;
		}
		free(split[i]);
		++i;
	}
	return (ret);
}

void	start_forking(int i, char *command, char *cmd)
{
	pid_t	pid;
	int		stat;

	if (g_val.cmd_table[i].cmd[0] != '\0')
	{
		pid = fork();
		if (pid < 0)
			printf("Error: fork not forked\n");
		else if (!pid)
		{
			if (change_in(i) < 0)
				exit(0);
			change_out(i);
			checking_commands(i, command, cmd);
		}
		else
		{
			g_val.cmd_table[i].pid = pid;
			parental_things(i);
			wait(&stat);
			g_val.last_returned = WEXITSTATUS(stat);
		}
	}
}

void	ft_fork(int i, char *cmd, char *command)
{
	pid_t	pid;
	int		j;
	int		stat;
	int		fd;

	if (ft_strncmp(command, "exit\0", 5) == 0 && g_val.cmd_count == 1)
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
			start_forking(i, command, cmd);
	}	
}
