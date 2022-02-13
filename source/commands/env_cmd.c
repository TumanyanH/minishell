/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:44 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/13 18:29:10 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_env(char *cmd)
{
	t_list	*temp;

	temp = g_val.env;
	if (is_space(*cmd) == 0 && *cmd != '\0')
		printf("minishell: env%s: command not found\n", cmd);
	else
	{
		while (is_space(*cmd))
			cmd++;
		if (*cmd == '\0')
		{
			while (temp)
			{
				printf("%s=%s\n", temp->content->envname, temp->content->envval);
				temp = temp->next;
			}
		}
		else
			printf("env: %s: No such file or directory\n", cmd);
	}
}
