/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/20 08:17:33 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_changer(char *env, char *new_val)
{
	int		i;

	i = 0;
	while (ft_strncmp(g_val.env->content->envname, env, ft_strlen(env)) != 0)
	{
		++i;
		g_val.env = g_val.env->next;
	}
	// free(g_val.env->content->envval);
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
		cmd = cmd_corrector(cmd);
		prev_dir = getcwd(cwd, PATH_MAX + 1);
		next_dir = ft_strjoin(cwd, "/");
		next_dir = ft_strjoin(next_dir, cmd);
		a = chdir(next_dir);
		if (a == 0)
		{
			env_changer("PWD", next_dir);
		}
		else
			printf("minishell: cd: %s: No such file or directory\n", cmd);
	}
}
