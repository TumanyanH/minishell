/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:05:37 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/11 20:40:57 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_echo(int fd, char **args)
{
	int	k;
	int	option;

	k = 0;
	option = 0;
	while (!ft_strncmp(args[k], "-n\0", 3))
	{
		option = 1;
		++k;
	}
	while (args[k] != NULL)
	{
		ft_putstr_fd(args[k], fd);
		++k;
		if (args[k])
			ft_putstr_fd(" ", fd);
	}
	if (!option)
		ft_putstr_fd("\n", fd);
	return (0);
}
