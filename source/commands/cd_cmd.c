/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/21 21:49:19 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_till_space(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i] != ' ' && i < ft_strlen(cmd))
		++i;
	return (i);	
}

char	*cmd_corrector(char *cmd)
{
	char	*res;
	int		i;
	int		index;

	i = 0;
	index = 0;
	res = (char *)malloc(ft_strlen(cmd) * sizeof(char) + 1);
	cmd = ft_strtrim(cmd, " ");
	if (cmd[i] == '.' && cmd[i + 1] == '/' && cmd[i + 2] == '\0')
		return (".");
	else if (cmd[i] == '.' && cmd[i + 1] == '/' && ft_isalpha(cmd[i + 1]))
		i += 2;
	else if (cmd[i] == '~' && cmd[i + 1] == '/')
		i += 2;
	else if (cmd[i] == '~' && cmd[i + 1] == '\0')
		++i;
	// else if (cmd[i] == '~' && ))
	// 	i += count_till_space(&(cmd[i]));
	while (cmd[i])
	{
		res[index] = cmd[i];
		++index;
		++i;
	}
	res[index] = '\0';
	return (res);
}

void	check_cd(char *cmd)
{
	int		a;
	char	prev_dir[PATH_MAX + 1];
	char	*next_dir;
	t_list	*temp;

	temp = find_env("HOME");
	cmd = cmd_corrector(cmd);
	getcwd(prev_dir, PATH_MAX + 1);
	if (*cmd == '\0')
	{
		chdir(temp->content->envval);
		next_dir = temp->content->envval;
	}
	else if (chdir(cmd) == -1)
	{
		next_dir = ft_strjoin(prev_dir, "/");
		next_dir = ft_strjoin(next_dir, cmd);
		if (!chdir(next_dir))
		{
			temp = find_env("PWD");
			temp->content->envval = next_dir;
		}
		else
			printf("minishell: cd: %s: No such file or directory\n", cmd); // heto exit
	}
	else
		next_dir = cmd;
	temp = find_env("PWD");
	temp->content->envval = next_dir;
	temp = find_env("OLDPWD");
	// printf("hey=%s\n", );
	temp->content->envval = prev_dir;
}
