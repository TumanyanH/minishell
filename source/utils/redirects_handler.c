/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:01:22 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/11 20:02:10 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_in(int i)
{
	int	fd;
	int	j;

	j = 0;
	fd = 0;
	if (i > 0 && i < g_val.cmd_count)
		fd = g_val.pipes[i - 1][0];
	while (g_val.cmd_table[i].redirects.in[j])
		j++;
	if (j > 0)
		fd = g_val.cmd_table[i].redirects.in[j - 1];
	if (g_val.cmd_table[i].cmd[0])
	{
		if (fd > 0)
			dup2(fd, 0);
	}
	else
		close(fd);
}

void	change_out(int i)
{
	int	fd;
	int	j;

	j = 0;
	fd = 0;
	while (g_val.cmd_table[i].redirects.out[j])
		j++;
	if (i < g_val.cmd_count - 1)
		fd = g_val.pipes[i][1];
	if (j > 0)
		fd = g_val.cmd_table[i].redirects.out[j - 1];
	if (fd > 0)
		dup2(fd, 1);
}
