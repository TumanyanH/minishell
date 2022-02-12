/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:32:19 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/12 15:35:59 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(char *cmd)
{
	if (is_space(*cmd) || *cmd == '\0')
		printf("%s\n", (g_val.envp[find_env(g_val.envp, "PWD")] + 4));
	else 
		printf("minishell: pwd%s: command not found\n", cmd);
}
 