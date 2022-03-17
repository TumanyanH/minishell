/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/17 19:43:00 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_change(char *new_val, char *env)
{
	int		i;
	char	buff[PATH_MAX + 1];

	i = 0;
	while (ft_strncmp(g_val.env->content->envname, env, ft_strlen(env)) != 0)
	{
		++i;
		g_val.env = g_val.env->next;
	}
	g_val.env->content->envval = malloc(sizeof(char) * ft_strlen(new_val) + 1);
	if (env[0] == 'P')
		g_val.env->content->envval = getcwd(buff, PATH_MAX + 1); // env ic hetoya tpum
	else
		g_val.env->content->envval = new_val;
	while (i > 0)
	{
		g_val.env = g_val.env->prev;
		--i;
	}
	return (0);
}

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
	char	cwd[PATH_MAX + 1];
	char	*next_dir;
	char	*prev_dir;

	// chdir("/var/root");
	cmd = cmd_corrector(cmd);
	if (*cmd == '\0')
		chdir(find_env("HOME"));
	else if (chdir(cmd) == -1)
	{
		prev_dir = getcwd(cwd, PATH_MAX + 1);
		next_dir = ft_strjoin(cwd, "/");
		next_dir = ft_strjoin(next_dir, cmd);
		printf("dir=%s\n", next_dir);
		if (!chdir(next_dir))
		{
			env_change("lalal", "PWD");
			env_change(prev_dir, "OLDPWD");
		}
		else
			printf("minishell: cd: %s: No such file or directory\n", cmd);
	}
}
