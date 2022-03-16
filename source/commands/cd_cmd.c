/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/16 18:03:58 by ster-min         ###   ########.fr       */
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

char	*cmd_corrector(char *cmd)
{
	char	*res;
	int		i;
	int		index;

	i = 0;
	index = 0;
	res = (char *)malloc(ft_strlen(cmd) * sizeof(char));
	while (is_space(cmd[i]))
		++i;
	if (cmd[i] == '.' && cmd[i + 1] == '/')
		i += 2;
	while (cmd[i] && !is_space(cmd[i]))
	{
		res[index] = cmd[i];
		++index;
		++i;
	}
	return (res);
}

void	check_cd(char *cmd)
{
	int		a;
	char	cwd[PATH_MAX + 1];
	char	*next_dir;
	char	*prev_dir;

	if (is_space(*cmd) == 0 && *cmd != '\0')
		printf("minishell: cd%s: command not found\n", cmd);
	else
	{
		printf("access=%d\n", access(cmd, F_OK));
		cmd = cmd_corrector(cmd);
		prev_dir = getcwd(cwd, PATH_MAX + 1);
		next_dir = ft_strjoin(cwd, "/");
		next_dir = ft_strjoin(next_dir, cmd);
		a = chdir(next_dir);
		if (a == 0)
		{
			env_change("lalal", "PWD");
			env_change(prev_dir, "OLDPWD");
		}
		else
			printf("minishell: cd: %s: No such file or directory\n", cmd);
	}
}
