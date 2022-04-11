/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:32:15 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/11 20:38:49 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_till_pipe(char *cmd, int i)
{
	int	count;

	count = 0;
	while (cmd[i] && cmd[i] != '|')
	{
		++i;
		++count;
	}
	return (count);
}

int	count_pipes(char *cmd, int i)
{
	int	count;

	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|')
			count++;
		i++;
	}
	return (count);
}

char	*cpy_till_pipe(char *cmd, int *i)
{
	char	*tmp;
	char	*tmp2;
	int		j;
	int		in_qutoes;

	j = *i;
	in_qutoes = 0;
	while (cmd[j])
	{
		if (cmd[j] == '\'' || cmd[j] == '\"')
			in_qutoes = !in_qutoes;
		if (cmd[j] == '|' && in_qutoes == 0)
			break ;
		j++;
	}
	tmp = ft_substr(cmd, *i, j - *i);
	tmp2 = ft_strtrim(tmp, " ");
	free(tmp);
	*i = j + 1;
	return (tmp2);
}
