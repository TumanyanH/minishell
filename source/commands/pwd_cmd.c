/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:32:19 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/13 16:43:34 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(char *cmd)
{
	if (is_space(*cmd) || *cmd == '\0')
		printf("%s\n", (find_env(g_val.env, "PWD")->envval));
	else
		printf("minishell: pwd%s: command not found\n", cmd);
}
