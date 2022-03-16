/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/16 17:39:59 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_dub_quote(char *str)
{
	int	i;

	i = 1;
	if ((str[0] == 39 || str[0] == 34)
		&& (str[ft_strlen(str) - 1] == 39 || str[ft_strlen(str) - 1] == 34)
		&& (str[ft_strlen(str)] == 39 || str[ft_strlen(str)] == 34))
	{
		while (i < ft_strlen(str) - 1)
		{
			if (str[i] == 39 || str[i] == 34)
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}

char	*general_check(char *cmd)
{
	int		i;
	int		count;
	int		index;
	char	*res;

	res = (char *)malloc(sizeof(char) * ft_strlen(cmd));
	i = 0;
	index = 0;
	count = 0;
	while (cmd[i] && !is_space(cmd[i]))
	{
		if (cmd[i] != 39 && cmd[i] != 34)
		{
			res[index] = ft_tolower(cmd[i]);
			++index;
		}
		else
			++count;
		++i;
		if (count % 2 == 1 && is_space(cmd[i]) && cmd[i] != '\0')
		{
			while (is_space(cmd[i]) && cmd[i] != '\0')
			{
				res[index] = ft_tolower(cmd[i]);
				++index;
				++i;
			}
		}
	}
	res[index] = '\0';
	return (res);
}

void	checking_commands(int i)
{
	char	*command;
	char	*cmd;
	char	**temp;

	cmd = ft_strtrim(g_val.cmd_table[i].cmd, " ");
	command = general_check(cmd);
	temp = ft_split(cmd, ' ');
	while (!is_space(*cmd) && *cmd)
		cmd++;
	if (cmd && ft_strncmp(command, "echo\0", 5) == 0)
		check_echo(cmd);
	else if (cmd && ft_strncmp(command, "cd\0", 3) == 0)
		check_cd(cmd);
	else if (cmd && ft_strncmp(command, "pwd\0", 4) == 0)
		check_pwd(cmd);
	else if (cmd && ft_strncmp(command, "export\0", 7) == 0)
		check_export(cmd);
	else if (cmd && ft_strncmp(command, "unset\0", 6) == 0)
		check_unset(cmd);
	else if (cmd && ft_strncmp(command, "env\0", 4) == 0)
		check_env(cmd);
	else if (cmd && ft_strncmp(command, "exit\0", 5) == 0)
		check_exit(cmd);
	else		
		printf("minishell: %s: command not found\n", temp[0]);
}

int	check_structure(char *cmd)
{
	int	i;

	i = 0;
	cmd = ft_strtrim(cmd, " ");
	if (cmd[i] == '|')
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '|')
		{
			while (is_space(cmd[++i]))
				;
			if ((cmd[i] == '\0' || cmd[i] == '|'))
				return (0);
		}
		++i;
	}
	return (1);
}

void	analyse_cmd(char *cmd, char **argv)
{
	int	i;

	if (cmd && ft_strlen(cmd) > 0)
	{
		g_val.pipes_count = count_pipes(cmd, 0) + 1;
		start_parse(cmd);
		i = -1;
		while (++i < g_val.pipes_count)
			checking_commands(i);
		clear_globs();
	}
}
