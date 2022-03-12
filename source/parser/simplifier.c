/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:01:05 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/11 21:22:55 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char    *reall_w_val(char *cmd, int *i)
// {   
//     char    *nw_cmd;

//     nw_cmd = malloc();
//     while (cmd[*i])
//     {
		
//         ++(*i);
//     }
// }

int count_till_var(char *cmd, int *i)
{
	int count;
	int j;

	j = *i;
	count = 0;
	while (cmd[j] && cmd[j] != '$')
	{
		if (cmd[j + 1] && !is_space(cmd[j + 1]))
			return (count);
		++count;
		++(j);
	}
	return (-1);
}

void simplify(char *cmd)
{
	int i;
	int left;
	int count;
	int sing_qute_det;
	char *fin_cmd;

	i = 0;
	left = 0;
	count = 0;
	sing_qute_det = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			sing_qute_det = !sing_qute_det;
		if (!sing_qute_det && cmd[i] == '$' && !is_space(cmd[i + 1]))
		{
			fin_cmd = ft_substr(cmd, left, count_till_var(cmd, left));
			// vopshm vonc jogum em petqa stexic sharunakes :D
		}
		++i;
	}
}