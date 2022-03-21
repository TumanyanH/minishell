/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/21 20:23:31 by htumanya         ###   ########.fr       */
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
	envname = ft_strtrim(envname, "\"\'");
	while (ft_strncmp(tmp->content->envname, envname,
			ft_strlen(envname)) != 0)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}
	return (tmp);
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
	
	envars = list_to_arr();
	pid = fork();
	if (pid < 0)
		printf("Error: fork not forked\n");
	else if (!pid)
	{
		if (g_val.cmd_table[i].has_pipe)
			dup2(g_val.cmd_table[i].pipes[0], STDIN_FILENO);
		dup2(STDOUT_FILENO, g_val.cmd_table[i].pipes[1]);
		close(g_val.cmd_table[i].pipes[1]);
		if (i != g_val.pipes_count - 1)
			dup2(g_val.cmd_table[i + 1].pipes[1], STDOUT_FILENO);
		
		execve(acc_check, ft_split(g_val.cmd_table[i].cmd, ' '), envars);
	}
	else
	{
		if (i < g_val.pipes_count)
			close (g_val.cmd_table[i].pipes[1]);
		waitpid(pid, NULL, 0);
	}
}
