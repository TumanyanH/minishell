/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/16 21:46:14 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_changer(char *env, char *new_val)
{
	t_list	*item;

	item = g_val.env;
	while (ft_strncmp(item->content->envname, env,
			ft_strlen(item->content->envname)) == 0)
	{
		item = item->next;
	}
	item->content->envval = new_val;
	return (0);
}

void	check_cd(char *cmd)
{
	int		a;
	char	cwd[PATH_MAX + 1];
	char	*next_dir;
	char	*prev_dir;

	if (is_space(*cmd) == 0 && *cmd != '\0')
		printf("minishell: cd%s: command not found\n", cmd);
	else
	{
		while (is_space(*cmd))
			cmd++;
		if (*cmd == '\0')
			chdir("/Users/ster-min/Desktop");
		prev_dir = getcwd(cwd, PATH_MAX + 1);
		next_dir = ft_strjoin(cwd, cmd);
		a = chdir(next_dir);
		if (a == 0)
		{
			// env_changer();
		}
		printf("\ns=%s\n%d\n", next_dir, a);
	}
}
