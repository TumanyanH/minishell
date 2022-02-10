/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:27 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/10 19:52:43 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	successful_exit(int a)
{
	a = 0;
	clear_history();
	clear_memory();
	printf("exit\n");
	exit(0);
}

void	check_exit(char *cmd)
{
	int	ret;

	if (*cmd == '\0')
		exit(0);
	else if (is_space(*cmd))
	{
		ret = ft_atoi(cmd);
		if (ret == -1)
		{
			printf("minishell: exit: %s: command not found\n", cmd);
			exit(127);
		}
		else if (ret == -2)
		{
			printf("minishell: exit: too many arguments\n");
			exit(1);
		}
		else if (ret >= 0 && ret <= 255)
			exit(ret);
		else if (ret > 255)
			exit (ret % 256);
	}
	printf("minishell: exit%s: command not found\n", cmd);
	exit(127);
}

void	exit_keypass(void)
{
	struct sigaction	sa;

	sa.sa_handler = successful_exit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
