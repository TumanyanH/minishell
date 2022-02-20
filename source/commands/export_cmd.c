/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:34:09 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/20 20:27:56 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_print(void)
{
	int	i;

	i = 0;
	while (g_val.env->next != NULL)
	{
		printf("declare -x %s=\"%s\"\n",
			g_val.env->content->envname, g_val.env->content->envval);
		g_val.env = g_val.env->next;
		++i;
	}
	while (i > 0)
	{
		g_val.env = g_val.env->prev;
		--i;
	}
}

void	export_error(char *cmd)
{
	int	i;

	i = 0;
	printf("minishell: export: '%s': not a valid identifier\n", cmd);
}

void	check_export(char *cmd)
{
	int	i;

	i = 0;
	if (is_space(*cmd) == 0 && *cmd != '\0')
		printf("minishell: export%s: command not found\n", cmd);
	else
	{
		while (is_space(cmd[i]))
			++i;
		if (cmd[i] == '\0')
			export_print();
		else if (cmd[i] != '_' && !ft_isalpha(cmd[i]))
			export_error(cmd + i);
	}
}
