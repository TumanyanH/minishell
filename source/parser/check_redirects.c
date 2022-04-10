/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:52:55 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/03 21:21:44 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	if (is_red_in > 2 || is_red_out > 2)
	{
		printf("wrong redirection\n");
		return (-1);
	}
	*count += i;
	if (is_red_in > 0 && is_red_in < 3 && is_red_out == 0)
		return (is_red_in);
	else if (is_red_out > 0 && is_red_out < 3 && is_red_in == 0)
		return (is_red_out + 2);
	return (0);
}

int	count_fp(char *cmd)
{
	int	i;

	i = 0;
	while (!is_space(cmd[i]) && cmd[i] && cmd[i] != '<' && cmd[i] != '>')
		++i;
	return (i);
}

char	*find_file(char *cmd, int *i)
{
	char	*fp;
	int		count;

	while (is_space(cmd[*i]))
		++(*i);
	count = count_fp(&(cmd[*i]));
	fp = (char *)malloc(sizeof(char) * (count + 1));
	ft_strlcpy(fp, (cmd + *i), count + 1);
	*i += ft_strlen(fp);
	return (fp);
}

int count_redirects(char *cmd, char red_type)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == red_type)
		{
			if (cmd[i + 1] == red_type)
				++i;
			++count;
		}
		++i;
	}
	return (count);
}

void	parse_redirects(char *cmd, int cmd_n)
{
	int	red;
	int i;
	int fd;
	int reds_in;
	int reds_out;

	i = 0;
	reds_in = 0;
	reds_out = 0;
	g_val.cmd_table[cmd_n].redirects.in = (int *)malloc(sizeof(int) * (count_redirects(cmd, '<') + 1));
	g_val.cmd_table[cmd_n].redirects.out = (int *)malloc(sizeof(int) * (count_redirects(cmd, '>') + 1));
	while (cmd[i])
	{
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			red = check_redirect(cmd + i, &i);
			if (red == -1)
				return ;
			else if (red == 1) // level 1, red - in
				g_val.cmd_table[cmd_n].redirects.in[reds_in++] = open(find_file(cmd, &i), O_RDONLY);
			else if (red == 2) // level 2, red - in
				g_val.cmd_table[cmd_n].redirects.in[reds_in++] = prompt_heredoc_v2(find_file(cmd, &i), cmd_n);
			else if (red == 3) // level 1, red - out
				g_val.cmd_table[cmd_n].redirects.out[reds_out++] = open(find_file(cmd, &i), O_CREAT | O_RDWR | O_TRUNC, 0644);
			else if (red == 4) // level 2, red - out
				g_val.cmd_table[cmd_n].redirects.out[reds_out++] = open(find_file(cmd, &i), O_CREAT | O_RDWR | O_APPEND, 0644);
		}
		else
			++i;
	}
	g_val.cmd_table[cmd_n].redirects.in[reds_in] = 0;
	g_val.cmd_table[cmd_n].redirects.out[reds_out] = 0;
	return ;
}
