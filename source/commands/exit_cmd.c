/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:27 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/05 21:43:38 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	successful_exit(int a)
{
	a = 0;
	clear_history();
	exit(0);
}

void	check_exit(char *cmd)
{
	if (ft_strlen(cmd) > 0 && ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		exit(0);
}

void	exit_keypass(void)
{
	struct sigaction	sa;

	sa.sa_handler = successful_exit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
