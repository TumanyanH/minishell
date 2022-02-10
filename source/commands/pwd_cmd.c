/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:32:19 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/10 20:56:17 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(char *cmd)
{
	if (is_space(*cmd))
		printf("%s\n", (g_val.envp[find_env(g_val.envp, "PWD")] + 4));
	else 
		printf("minishell: pwd%s: command not found\n", cmd);
}
 