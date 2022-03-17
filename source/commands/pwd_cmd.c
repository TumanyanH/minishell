/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:32:19 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/17 18:05:49 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_pwd(char *cmd)
{
	char	cwd[PATH_MAX + 1];

	printf("%s\n", getcwd(cwd, PATH_MAX + 1));
}
