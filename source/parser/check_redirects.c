/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:52:55 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/27 22:09:41 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief check for redirections <, >, <<, >>
 * 
 * @param cmd 
 * @return 1 - <, 2 - >, 3 - <<, 4 - >> 
 */
int	check_redirect(char *cmd)
{
	int	i;
	int	is_red_in;
	int	is_red_out;

	i = 0;
	is_red_in = 0;
	is_red_out = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<')
			is_red_in++;
		else if (cmd[i] == '>')
			is_red_out++;
		++i;
	}
	if (is_red_in > 0 && is_red_in < 3 && is_red_out == 0)
		return (is_red_in);
	else if (is_red_out > 0 && is_red_out < 3 && is_red_in == 0)
		return (is_red_out + 2);
	return (0);
}

void	complete_redirects(char **parts)
{
	int i;
	t_redirect red; 
	i = 0;
	while (parts[i])
	{
		if (check_redirect(parts[i]) == 1 || check_redirect(parts[i]) == 3)
		{
			g_val.redirects.in.level = check_redirect(parts[i]) / 2 + 0.5;
			g_val.redirects.in.path = parts[i + 1];
		}
		else if (check_redirect(parts[i]) == 2 || check_redirect(parts[i]) == 4)
		{
			g_val.redirects.out.level = check_redirect(parts[i]) / 2;
			g_val.redirects.out.path = parts[i + 1];
		}
		++i;
	}
}