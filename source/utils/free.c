/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:41:10 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/03 21:51:11 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_2d(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	clear_memory()
{
	
}

void	clear_globs( void )
{
	int	i;
	int	j;

	i = 0;
	while (i < g_val.cmd_count)
	{
		// if (g_val.cmd_table[i].cmd)
		// 	free(g_val.cmd_table[i].cmd);
		// j = 0;
		// while (g_val.cmd_table[i].redirects.in[j].path)
		// {
		// 	if (g_val.cmd_table[i].redirects.in[j].path)
		// 		free(g_val.cmd_table[i].redirects.in[j].path);
		// 	++j;
		// }
		// free(g_val.cmd_table[i].redirects.in);
	}
}
