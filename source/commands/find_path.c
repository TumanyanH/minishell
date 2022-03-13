/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/12 21:17:37 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_env(char *envname)
{
	t_list	*tmp;

	tmp = g_val.env;
	while (ft_strncmp(tmp->content->envname, envname,
			ft_strlen(tmp->content->envname)) != 0)
	{
		tmp = tmp->next;
	}
	return (tmp->content->envval);
}
