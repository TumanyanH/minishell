/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/18 21:21:04 by ster-min         ###   ########.fr       */
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

	i = 0;
	index = 0;
	cmd = ft_strtrim(cmd, " ");
	if (cmd[0] == '~')
		res = ft_strjoin(find_env("HOME"), cmd + 1);
	else
		return (cmd);
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
		// printf("dir=%s\n", next_dir);
		if (!chdir(next_dir))
		{
			env_change("lalal", "PWD");
			env_change(prev_dir, "OLDPWD");
		}
		else
			printf("minishell: cd: %s: No such file or directory\n", cmd);
	}
}
