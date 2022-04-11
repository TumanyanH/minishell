/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:32:19 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 13:33:27 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_pwd(int fd)
{
	char	cwd[PATH_MAX + 1];
	char	*ret;
	t_list	*old;

	ret = getcwd(cwd, PATH_MAX + 1);
	if (ret)
		printf("%s\n", ret);
	else
	{
		old = find_env("PWD");
		printf("%s\n", old->content->envval);
	}
	return (0);
}
