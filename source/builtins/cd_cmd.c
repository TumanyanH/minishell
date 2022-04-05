/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 13:40:20 by ster-min         ###   ########.fr       */
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

void	check_cd(char **args)
{
	int		a;
	char	prev_dir[PATH_MAX + 1];
	char	next_dir[PATH_MAX + 1];
	t_list	*temp;
	t_list	*old;
	char	*lala;
	char	*lala2;

	temp = find_env("HOME");
	args[0] = cmd_corrector(args[0]);
	old = find_env("OLDPWD");
	old->content->envval = getcwd(prev_dir, PATH_MAX + 1);
	// lala2 = prev_dir;
	if (*args[0] == '\0')
		chdir(temp->content->envval);
	else if (*args[0] == '-')
	{
		old = find_env("OLDPWD");
		if (old->content->envval)
		{
			if (chdir(old->content->envval) == -1)
			{
				printf("minishell: cd: %s: No such file or directory\n", args[0]);
				exit(1);
			}
		}
	}
	else if (chdir(args[0]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", args[0]);
		exit(1);
	}
	// lala = next_dir;
	// printf("%s\n", prev_dir);
	temp = find_env("PWD");
	temp->content->envval = getcwd(next_dir, PATH_MAX + 1);
	// exit(0);
}
