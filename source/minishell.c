/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:30:26 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/13 19:32:02 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initial(char **envp)
{
	g_val.env = fill_env_list(envp);
	// g_val.redirects.in.path = NULL;
	// g_val.redirects.out.path = NULL;
}

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	char	**argv;
	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
	initial(envp);
	// printf("%s\n",simplifier("asd${PATH}"));
	while (1)
	{
		cmd = readline("minishell> ");
		if (cmd[0] != '\0')
			add_history(cmd);
		if (cmd == NULL)
			successful_exit(0);
		if (check_quotes(cmd) == 0)
		{
			ft_putstr_fd("Invalid quotes\n", 1);
			continue;
		}
		analyse_cmd(cmd, argv);
	}
	return (0);
}