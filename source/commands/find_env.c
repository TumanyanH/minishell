/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/18 16:38:24 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_env(char *envname)
{
	t_list	*tmp;
	int		flag;

	tmp = g_val.env;
	if (envname == NULL)
		return (NULL);
	envname = ft_strtrim(envname, "\"\'");
	while (ft_strncmp(tmp->content->envname, envname,
			ft_strlen(envname)) != 0)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}
	return (tmp->content->envval);
}

char	*ft_access(char *command)
{
	char	**path;
	char	*abs_path;
	int		i;

	i = 0;
	path = ft_split(find_env("PATH"), ':');
	while (path[i])
	{
		abs_path = ft_strjoin(ft_strjoin(path[i], "/"), command);
		if (!access(abs_path, F_OK))
			return (abs_path);
		++i;
	}
	return (NULL);
}

void	ft_exec(int i, char *acc_check)
{
	char	**envars;
	pid_t	pid;
	int		status;

	envars = list_to_arr();
	pid = fork();
	if (pid < 0)
		printf("Error: fork not forked\n");
	else if (!pid)
		execve(acc_check, ft_split(g_val.cmd_table[i].cmd, ' '), envars);
	else
		waitpid(pid, NULL, 0);
}
