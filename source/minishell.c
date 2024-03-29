/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:30:26 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/16 20:11:46 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initial(char **envp)
{
	g_val.env = fill_env_list(envp);
	g_val.cmd_count = 0;
}

void	sigint_handler(int i)
{
	i = 0;
	if (g_val.cmd_count == 0)
	{
		printf("\n");
		printf("\033[2D");
		rl_on_new_line();
		rl_redisplay();
	}
	while (i < g_val.cmd_count)
	{
		if (g_val.cmd_table[i].pid > 0)
		{
			printf("\033[2D");
			kill(g_val.cmd_table[i].pid, SIGTERM);
		}
		++i;
	}
}

void	sigquit_handler(int i)
{
	i = 0;
	while (i < g_val.cmd_count)
	{
		if (g_val.cmd_table[i].pid > 0)
		{
			printf("\033[2D");
			kill(g_val.cmd_table[i].pid, SIGQUIT);
		}
		++i;
	}
}

void	exiter(void)
{
	printf("\033[2D");
	printf("exit\n");
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	char	**argv;
	char	path[PATH_MAX + 1];

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
	initial(envp);
	while (1)
	{
		cmd = readline("minishell> ");
		if (cmd == NULL)
			exiter();
		if (cmd[0] != '\0')
			add_history(cmd);
		if (!check_structure(cmd))
			printf("minishell: syntax error\n");
		else if (check_quotes(cmd) == 0)
			ft_putstr_fd("Invalid quotes\n", 1);
		else
			analyse_cmd(cmd, argv);
	}
	return (0);
}
