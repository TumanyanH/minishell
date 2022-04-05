/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:35:06 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/04 20:49:44 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_unset(char **args)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (*args[i] != '\0')
	{
		temp = find_env(args[i]);
		printf("temp=%s-\n", temp->content->envval);
		if (temp)
			ft_lstdelone(&g_val.env, temp);
		++i;
	}
	exit(0);
}
