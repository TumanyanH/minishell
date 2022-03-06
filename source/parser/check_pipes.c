/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:32:15 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/06 21:32:32 by htumanya         ###   ########.fr       */
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
	int count;

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
	int		j;
	
	j = *i;
	while (cmd[j] && cmd[j] != '<' && cmd[j] != '>' && cmd[j] != '|')
		j++;
	tmp = ft_substr(cmd, *i, j - *i);
	*i += j;
	return (tmp);
}
