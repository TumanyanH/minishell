/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:01:42 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/10 19:51:31 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	start_parse(char *cmd_line)
{
	int	i;
	int pipes_count;
	int each_cmd;

	each_cmd = 0;
	/** + 2 for last command and NULL-terminate */
	pipes_count = count_pipes(cmd_line, 0) + 2;
	i = 0;
	g_val.cmd_table = (t_pipes *)malloc(sizeof(t_pipes) * (pipes_count));
	while (i < ft_strlen(cmd_line))
	{
		// if (cmd_line[i] == '>' || cmd_line[i] == '<')
		// {
		// 	parse_redirects(cmd_line, &i);
		// 	while (is_space(cmd_line[i]))
		// 		i++;
		// }
		// else
		// {
		g_val.cmd_table[each_cmd].cmd = cpy_till_pipe(cmd_line, &i);
		parse_redirects(g_val.cmd_table[each_cmd].cmd, each_cmd);
		if (each_cmd > 0)
		{
			g_val.cmd_table[each_cmd].has_pipe = 1;
			while (is_space(cmd_line[i]))// || cmd_line[i] == '|')
				i++;
		}
		each_cmd++;
		// }
		// ++i;
	}
	return (0);
}
