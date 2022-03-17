/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:34:09 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/17 18:05:09 by htumanya         ###   ########.fr       */
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
	int		i;
	char	**splited;

	i = 0;
	printf("lll\n");
	while (is_space(cmd[i]))
		++i;
	if (cmd[i] == '\0')
		export_print();
	else
	{
		splited = arg_split(cmd);
		int i = 0;
		while (splited[i])
		{
			printf("%s\n", splited[i]);
			++i;
		}
	}
}
