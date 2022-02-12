/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:30:26 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/12 20:53:13 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	initial(char **envp)
{
	exit_keypass();
	find_path(&g_val.path, envp);
	g_val.envp = envp;
	g_val.env = fill_env_list(envp);
	t_env_item	*temp;
	// while (g_val.env->next)
	// {
	temp = g_val.env->content;
	printf("%c - %c\n", *temp->envname, *temp->envval);
// }
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
