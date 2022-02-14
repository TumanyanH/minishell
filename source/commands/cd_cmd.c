/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:33:31 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/14 18:08:07 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_cd(char *cmd)
{
	int		a;
	char	cwd[256];
	char	*next_dir;

	if (is_space(*cmd) == 0 && *cmd != '\0')
		printf("minishell: cd%s: command not found\n", cmd);
	while (is_space(*cmd))
		cmd++;
	getcwd(cwd, sizeof(cwd));
	next_dir = ft_strjoin(cwd, cmd);
	a = chdir(next_dir);
	printf("\ns=%s\n%d\n", next_dir, a);
}
