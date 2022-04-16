/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:52:55 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/16 18:39:13 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_red(int is_red_in, int is_red_out)
{
	if (is_red_in > 0 && is_red_in < 3 && is_red_out == 0)
		return (is_red_in);
	else if (is_red_out > 0 && is_red_out < 3 && is_red_in == 0)
		return (is_red_out + 2);
	return (0);
}

/**
 * @brief check for redirections <, >, <<, >>
 * 
 * @param cmd 
 * @return 1 - <, 2 - <<, 3 - >, 4 - >> 
 */
int	check_redirect(char *cmd, int *count)
{
	int	i;
	int	is_red_in;
	int	is_red_out;

	i = 0;
	is_red_in = 0;
	is_red_out = 0;
	while (cmd[i] == '<' || cmd[i] == '>')
	{
		if (cmd[i] == '<')
			is_red_in++;
		else if (cmd[i] == '>')
			is_red_out++;
		++i;
	}
	if (is_red_in > 2 || is_red_out > 2 || (is_red_in == 1 && is_red_out == 1))
	{
		printf("minishell: syntax error near unexpected token\n");
		return (-1);
	}
	*count += i;
	return (find_red(is_red_in, is_red_out));
}

void	parse_norme2(char *cmd, int *i, int red, int *reds_out)
{
	if (red / 100 == 3)
		g_val.cmd_table[red % 100].redirects.out[(*reds_out)++] = open(
				find_file(cmd, i), O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (red / 100 == 4)
		g_val.cmd_table[red % 100].redirects.out[(*reds_out)++] = open(
				find_file(cmd, i), O_CREAT | O_RDWR | O_APPEND, 0644);
}

int	parse_norme(char *cmd, int cmd_n, int *reds_in, int *reds_out)
{
	int	i;
	int	red;

	red = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			red = check_redirect(cmd + i, &i);
			if (red == -1)
				return (-1);
			else if (red == 1)
				g_val.cmd_table[cmd_n].redirects.in[(*reds_in)++] = open(
						find_file(cmd, &i), O_RDONLY);
			else if (red == 2)
				g_val.cmd_table[cmd_n].redirects.in[(*reds_in)++] = pr_heredoc(
						find_file(cmd, &i), cmd_n);
			else if (red == 3 || red == 4)
				parse_norme2(cmd, &i, red * 100 + cmd_n, reds_out);
		}
		else
			++i;
	}
	return (0);
}

int	parse_redirects(char *cmd, int cmd_n)
{
	int	i;
	int	red;
	int	reds_in;
	int	reds_out;

	reds_in = 0;
	reds_out = 0;
	g_val.cmd_table[cmd_n].redirects.in = (int *)malloc(sizeof(int)
			* (count_redirects(cmd, '<') + 1));
	g_val.cmd_table[cmd_n].redirects.out = (int *)malloc(sizeof(int)
			* (count_redirects(cmd, '>') + 1));
	if (parse_norme(cmd, cmd_n, &reds_in, &reds_out) == -1)
		return (-1);
	g_val.cmd_table[cmd_n].redirects.in[reds_in] = 0;
	g_val.cmd_table[cmd_n].redirects.out[reds_out] = 0;
	return (0);
}
