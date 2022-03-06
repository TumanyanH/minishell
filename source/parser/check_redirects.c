/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:52:55 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/03 19:25:08 by htumanya         ###   ########.fr       */
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
	while (!is_space(cmd[i]))
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
	ft_strlcpy(fp, (cmd + *i), count);
	return (fp);
}

void	parse_redirects(char *cmd, int *i)
{
	int	red;

	red = check_redirect(cmd + *i, i);
	if (red == 1)
	{
		g_val.redirects.in.level = 1;
		g_val.redirects.in.path = find_file(cmd, i);
	}
	else if (red == 2)
	{
		g_val.redirects.in.level = 2;
		g_val.redirects.in.path = find_file(cmd, i);
	}
	else if (red == 3)
	{
		g_val.redirects.out.level = 1;
		g_val.redirects.out.path = find_file(cmd, i);
	}
	else if (red == 4)
	{
		g_val.redirects.out.level = 2;
		g_val.redirects.out.path = find_file(cmd, i);
	}
}
