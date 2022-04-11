/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:44 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/11 13:27:10 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_error(int fd, char *cmd)
{
	ft_putstr_fd("minishell: cd: ", fd);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd(": No such file or directory\n", fd);
}

int	check_env(int fd, char **args)
{
	t_list	*temp;
	t_list	*under_line;

	temp = g_val.env;
	if (args[0][0] == '\0')
	{
		under_line = find_env("_");
		under_line->content->envval = ft_strjoin("/usr/bin/env", NULL);
		while (temp && temp->content->env_print == 1)
		{
			ft_putstr_fd(temp->content->envname, fd);
			ft_putstr_fd("=", fd);
			ft_putstr_fd(temp->content->envval, fd);
			ft_putstr_fd("\n", fd);
			temp = temp->next;
		}
		return (0);
	}
	else
		env_error(fd, args[0]);
	return (127);
}
