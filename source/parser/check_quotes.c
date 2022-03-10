/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:13:47 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/07 19:35:54 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quote_run(char *cmd, char quote, int *i)
{
	while (cmd[*i])
	{
		if (cmd[*i] == quote)
			return (1);
		(*i)++;
	}
	return (0);
}

int	check_quotes(char *cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i += 1;
			ret = quote_run(cmd, '\'', &i);
		}
		if (cmd[i] == '\"')
		{
			i += 1;
			ret = quote_run(cmd, '\"', &i);
		}
		i++;
	}
	return (ret);
}
