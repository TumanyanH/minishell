/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:01:42 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/03 21:50:55 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_pipes()
{
	int i;

	i = 0;
	if (g_val.cmd_count == 1)
	{
		g_val.pipes = (int **)malloc(sizeof(int *));
		g_val.pipes[0] = (int *)malloc(8);
		
		pipe(g_val.pipes[0]);
	}
	else
	{
		g_val.pipes = (int **)malloc((g_val.cmd_count - 1) * sizeof(int *));
		while (i < g_val.cmd_count - 1)
		{
			g_val.pipes[i] = (int *)malloc(8);
			pipe(g_val.pipes[i]);
			++i;
		}	
	}
}

int	check_structure(char *cmd)
{
	int	i;

	i = 0;
	cmd = ft_strtrim(cmd, " ");
	if (cmd[i] == '|')
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '|')
		{
			while (is_space(cmd[++i]))
				;
			if ((cmd[i] == '\0' || cmd[i] == '|'))
				return (0);
		}
		++i;
	}
	return (1);
}

int	start_parse(char *cmd_line)
{
	int		i;
	int		each_cmd;
	char	*temp;

	each_cmd = 0;
	g_val.cmd_count = count_pipes(cmd_line, 0) + 1;
	init_pipes();
	i = 0;
	g_val.cmd_table = (t_commands *)malloc(sizeof(t_commands) * (g_val.cmd_count));
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
	while (++i < g_val.cmd_count)
	{
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
