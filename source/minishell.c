/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:30:26 by htumanya          #+#    #+#             */
/*   Updated: 2021/11/01 15:10:13 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void initial()
{
	exit_keypass();
}

int	main(void)
{
	char	*cmd;
	
	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
	initial();
	while (1)
	{
		cmd = readline("minishell> ");
		analyse_cmd(cmd);
	}
	return (0);
}
