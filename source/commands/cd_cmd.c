/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/22 17:46:17 by ster-min         ###   ########.fr       */
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
		// temp = find_env("OLDPWD");
		// temp->content->envval = prev_dir;
	}
	else if (chdir(cmd) == -1)
	{
		next_dir = ft_strjoin(prev_dir, "/");
		next_dir = ft_strjoin(next_dir, cmd);
		if (!chdir(next_dir))
		{
			temp = find_env("PWD");
			// temp->content->envval = next_dir;
		}
		else
		{
			printf("minishell: cd: %s: No such file or directory\n", cmd);
			return ;
		}
	}
	else
		next_dir = cmd;
	temp = find_env("PWD");
	temp->content->envval = next_dir;
	temp = find_env("OLDPWD");
	temp->content->envval = prev_dir;
	printf("hey=%s\n", prev_dir);
}
