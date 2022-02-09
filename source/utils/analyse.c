/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/06 16:36:10 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	analyse_cmd(char *cmd, char **argv)
{
	if (cmd && ft_strlen(cmd) > 0)
	{
		add_history(cmd);
		check_exit(cmd);
		if (ft_strncmp(cmd, "whereis", 7) == 0)
			exec_echo(cmd);
	}
}
