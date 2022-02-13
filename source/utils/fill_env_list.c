/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:28:26 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/13 17:38:52 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*fill_env_list(char **envp)
{
	int			i;
	char		**env_dets;
	t_list		*env;
	t_env_item	*item;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		env_dets = ft_split_by_eq(envp[i]);
		item = (t_env_item *)malloc(sizeof(t_env_item));
		item->envname = env_dets[0];
		item->envval = env_dets[1];
		ft_lstadd_back(&env, ft_lstnew(item));
		// free_2d(env_dets);
		// env = env->next;
		i++;
		// printf("%s - %s\n", env->content->envname, env->content->envval);
	}
	return (env);
}
