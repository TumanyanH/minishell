/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:44 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 13:40:42 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_env(char **args)
{
	t_list	*temp;

	temp = g_val.env;
	if (*args[0] == '\0')
	{
		while (temp)
		{
			printf("%s=%s\n", temp->content->envname, temp->content->envval);
			temp = temp->next;
		}
		exit(0);
	}
	else
		printf("env: %s: No such file or directory\n", args[0]);
	exit(127);
}
