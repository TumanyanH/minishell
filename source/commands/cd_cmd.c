/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/23 21:26:41 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_till_space(char *cmd)
{
	int	i;

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
	t_list	*temp;

	i = 0;
	index = 0;
	temp = find_env("HOME");
	cmd = ft_strtrim(cmd, " ");
	if (cmd[0] == '~')
		res = ft_strjoin(temp->content->envval, cmd + 1);
	else
		return (cmd);
	return (res);
}

char	*make_abs_path(char *arg)
{
	int	count_back;

	count_back = 0;
	while (ft_strncmp(arg, "../", 3))
	{
		arg += 3;
		// arg = 
	}
	return (arg);
}

void	check_cd(char *cmd)
{
	int		a;
	char	prev_dir[PATH_MAX + 1];
	char	*next_dir;
	t_list	*temp;
	t_list	*old;

	temp = find_env("HOME");
	cmd = cmd_corrector(cmd);
	getcwd(prev_dir, PATH_MAX + 1);
	if (*cmd == '\0')
	{
		chdir(temp->content->envval);
		next_dir = temp->content->envval;
	}
	else if (*cmd == '-')
	{
		old = find_env("OLDPWD");
		if (old->content->envval)
		{
			if (chdir(old->content->envval) == -1)
			{
				printf("minishell: cd: %s: No such file or directory\n", cmd);
			}
		}
	}
	else if (chdir(cmd) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", cmd);
		return ;
	}
	else
		next_dir = cmd;
	temp = find_env("PWD");
	temp->content->envval = next_dir;
	temp = find_env("OLDPWD");
	temp->content->envval = prev_dir;
}
