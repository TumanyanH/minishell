/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:05:37 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/04 20:26:03 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_echo(char **args)
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
		printf("%s", args[k]);
		++k;
		if (args[k])
			printf(" ");
	}
	if (!option)
		printf("\n");
	return (0);
}
