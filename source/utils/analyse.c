/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/12 21:13:28 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	checking_commands(char *cmd)
{
	while (is_space(*cmd))
		cmd++;
	if (cmd && ft_strncmp(cmd, "echo", 4) == 0)
		check_echo(cmd + 4);
	else if (cmd && ft_strncmp(cmd, "cd", 2) == 0)
		check_cd(cmd + 2);
	else if (cmd && ft_strncmp(cmd, "pwd", 3) == 0)
		check_pwd(cmd + 3);
	else if (cmd && ft_strncmp(cmd, "export", 6) == 0)
		check_export(cmd + 6);
	else if (cmd && ft_strncmp(cmd, "unset", 5) == 0)
		check_unset(cmd + 5);
	else if (cmd && ft_strncmp(cmd, "env", 3) == 0)
		check_env(cmd + 3);
	else if (cmd && ft_strncmp(cmd, "exit", 4) == 0)
		check_exit(cmd + 4);
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
