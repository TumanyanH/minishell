/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:05:37 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/07 17:46:22 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_echo( char *cmd )
{
	char	*f_path;
	char	**cmd_details;

	f_path = ft_strjoin(g_val.path, "/echo");
	cmd_details = ft_split(cmd, ' ');
	execve(g_val.path, cmd_details, g_val.envp);
	execve(g_val.path, cmd_details, g_val.envp);
	free(f_path);
	free_2d(&cmd_details);
	return (1);
}
