/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 20:48:10 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*find_env(char *envname)
{
	t_list	*tmp;
	int		flag;

	tmp = g_val.env;
	if (envname == NULL)
		return (NULL);
	while (ft_strncmp(tmp->content->envname, envname,
			ft_strlen(envname)) != 0)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}
	return (tmp);
}

int	find_slash(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (1);
		cmd++;
	}
	return (0);
}

char	*ft_access(char *command)
{
	char	**path;
	char	*abs_path;
	int		i;
	t_list	*temp;

	i = 0;
	temp = find_env("PATH");
	path = ft_split(temp->content->envval, ':');
	if (find_slash(command))
	{
		if (!access(command, F_OK))
			return (command);
	}
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
	int		j;

	j = -1;
	envars = list_to_arr();
	execve(acc_check, ft_split(g_val.cmd_table[i].cmd, ' '), envars);
	while (envars[++j])
		free(envars[j]);
	free(envars);
}
