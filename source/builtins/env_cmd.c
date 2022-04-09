/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:44 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 13:40:42 by ster-min         ###   ########.fr       */
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

	temp = g_val.env;
	if (args[0][0] == '\0')
	{
		while (temp)
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
