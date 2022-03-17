/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:44 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/17 18:06:25 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_env(char *cmd)
{
	t_list	*temp;

	temp = g_val.env;
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
