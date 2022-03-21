/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:01:42 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/21 20:04:18 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start_parse(char *cmd_line)
{
	int		i;
	int		each_cmd;
	char	*temp;

	each_cmd = 0;
	g_val.pipes_count = count_pipes(cmd_line, 0) + 1;
	i = 0;
	g_val.cmd_table = (t_pipes *)malloc(sizeof(t_pipes) * (g_val.pipes_count));
	while (i < ft_strlen(cmd_line))
	{
		g_val.cmd_table[each_cmd].cmd = cpy_till_pipe(cmd_line, &i);
		parse_redirects(g_val.cmd_table[each_cmd].cmd, each_cmd);
		if (each_cmd > 0)
			g_val.cmd_table[each_cmd].has_pipe = 1;
		else
			g_val.cmd_table[each_cmd].has_pipe = 0;
		while (is_space(cmd_line[i]))
				i++;
		each_cmd++;
	}
	i = -1;
	while (++i < g_val.pipes_count)
	{
		pipe(g_val.cmd_table[i].pipes);
		temp = filter_cmd(g_val.cmd_table[i].cmd);
		if (g_val.cmd_table[i].cmd)
			free(g_val.cmd_table[i].cmd);
		g_val.cmd_table[i].cmd = ft_strdup(temp);
		if (temp)
			free(temp);
		temp = simplifier(g_val.cmd_table[i].cmd);
		// if (g_val.cmd_table[i].cmd)
		// 	free(g_val.cmd_table[i].cmd);
		g_val.cmd_table[i].cmd = ft_strdup(temp);
		if (temp)
			free(temp);
	}
	return (0);
}
