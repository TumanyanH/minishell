/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/17 21:07:22 by ster-min         ###   ########.fr       */
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
	while (!is_space(cmd[i]) && cmd[i])
	{
		if (cmd[i] != 39 && cmd[i] != 34)
		{
			res[index] = ft_tolower(cmd[i]);
			++index;
		}
		else
			++count;
		++i;
		if (count % 2 == 1)
		{
			while (is_space(cmd[i]) && cmd[i])
			{
				res[index] = ft_tolower(cmd[i]);
				++index;
				++i;
			}
		}
	}
	return (res);
}

void	checking_commands(char *cmd)
{
	char	*command;

	while (is_space(*cmd))
		cmd++;
	command = general_check(cmd);
	while (!is_space(*cmd) && *cmd)
		cmd++;
	if (cmd && ft_strncmp(command, "echo", 4) == 0)
		check_echo(cmd);
	else if (cmd && ft_strncmp(command, "cd", 2) == 0)
		check_cd(cmd);
	else if (cmd && ft_strncmp(command, "pwd", 3) == 0)
		check_pwd(cmd);
	else if (cmd && ft_strncmp(command, "export", 6) == 0)
		check_export(cmd);
	else if (cmd && ft_strncmp(command, "unset", 5) == 0)
		check_unset(cmd);
	else if (cmd && ft_strncmp(command, "env", 3) == 0)
		check_env(cmd);
	else if (cmd && ft_strncmp(command, "exit", 4) == 0)
		check_exit(cmd);
	else
		printf("minishell: %s: command not found\n", command);
}

void	analyse_cmd(char *cmd, char **argv)
{
	char	**pipes;
	int		i;

	if (cmd && ft_strlen(cmd) > 0)
	{
		add_history(cmd);
		pipes = ft_split(cmd, '|');
		checking_commands(pipes[0]);
		// if (ft_strncmp(cmd, "whereis", 7) == 0)
		// 	exec_echo(cmd);
	}
}
