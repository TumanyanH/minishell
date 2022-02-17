/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:32:19 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/15 16:11:42 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(char *cmd)
{
	char	cwd[PATH_MAX + 1];

	if (is_space(*cmd) || *cmd == '\0')
		printf("%s\n", getcwd(cwd, PATH_MAX + 1));
	else
		printf("minishell: pwd%s: command not found\n", cmd);
}
