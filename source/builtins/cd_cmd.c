/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/14 20:20:45 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	cd_error(int fd, char *cmd)
{
	ft_putstr_fd("minishell: cd: ", fd);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd(": No such file or directory\n", fd);
	return (1);
}

void	change_pwd(char *next_dir, char *prev_dir)
{
	t_list	*temp;
	t_list	*old;

	old = find_env("OLDPWD");
	temp = find_env("PWD");
	temp->content->envval = ft_strjoin(getcwd(next_dir, PATH_MAX + 1), NULL);
	old->content->envval = ft_strjoin(prev_dir, NULL);
}

int	print_error(void)
{
	printf("cd: error retrieving current\
directory: getcwd: cannot access parent\
directories: No such file or directory\n");
	return (0);
}

int	check_cd(int fd, char **args)
{
	char	prev_dir[PATH_MAX + 1];
	char	next_dir[PATH_MAX + 1];
	t_list	*temp;
	t_list	*old;
	char	*check;

	temp = find_env("HOME");
	args[0] = cmd_corrector(args[0]);
	old = find_env("OLDPWD");
	if (!getcwd(prev_dir, PATH_MAX + 1))
		return (print_error());
	if (*args[0] == '\0')
		chdir(temp->content->envval);
	else if (*args[0] == '-')
	{
		if (old->content->envval)
		{
			if (chdir(old->content->envval) == -1)
				return (cd_error(fd, args[0]));
		}
	}
	else if (chdir(args[0]) == -1)
		return (cd_error(fd, args[0]));
	change_pwd(next_dir, prev_dir);
	return (0);
}
