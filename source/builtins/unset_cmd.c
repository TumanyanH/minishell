/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:06 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/07 21:13:07 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_unset(int fd, char **args)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (args[i] != NULL)
	{
		temp = find_env(args[i]);
		if (temp)
			ft_lstdelone(&g_val.env, temp);
		++i;
	}
	return (0);
}
