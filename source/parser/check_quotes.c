/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:13:47 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/06 17:32:55 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quotes(char *cmd)
{
	int	single_quote;
	int	double_quote;
	int	i;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			single_quote++;
		else if (cmd[i] == '\"')
			double_quote++;
		i++;
	}
	return (single_quote % 2 == 0 && double_quote % 2 == 0);
}
