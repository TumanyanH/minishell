/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:01:42 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/11 20:38:17 by ster-min         ###   ########.fr       */
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
	for (int j = 0; j < pipes_count; ++j)
		printf("%d - cmd=%s, pipe=%d\n", j, g_val.cmd_table[j].cmd, g_val.cmd_table[j].has_pipe);
	return (0);
}


// <<asdf echo lalala |  ls -la  | pwd >sd echo alalal