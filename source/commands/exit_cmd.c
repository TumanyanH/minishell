/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:27 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/17 21:36:58 by ster-min         ###   ########.fr       */
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
			printf("minishell: exit: %s: numeric argument required\n", cmd);
			exit(127);
		}
		else if (ret == -2)
			printf("minishell: exit: too many arguments\n");
		else if (ret >= 0 && ret <= 255)
			exit(ret);
		else if (ret < 0)
		{
			while (ret < 0)
				ret += 256;
			exit (ret);
		}
		else if (ret > 255)
			exit (ret % 256);
	}
	else
		printf("minishell: exit%s: command not found\n", cmd);
}

void	exit_keypass(void)
{
	struct sigaction	sa;

	sa.sa_handler = successful_exit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
