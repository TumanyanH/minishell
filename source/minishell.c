/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:30:26 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/13 16:46:51 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initial(char **envp)
{
	exit_keypass();
	g_val.env = fill_env_list(envp);
}

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	char	**argv;

	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
	initial(envp);
	while (1)
	{
		cmd = readline("minishell> ");
		if (cmd == NULL)
			successful_exit(0);
		analyse_cmd(cmd, argv);
	}
	return (0);
}
