/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:28:26 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/16 17:19:24 by ster-min         ###   ########.fr       */
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
		i++;
	}
	return (env);
}

int	count_env(void)
{
	int		len;
	t_list	*temp;

	len = 0;
	temp = g_val.env;
	while (temp)
	{
		temp = temp->next;
		++len;
	}
	return (len);
}

char	**list_to_arr(void)
{
	char	**res;
	int		count;
	int		i;
	t_list	*temp;

	i = 0;
	temp = g_val.env;
	count = count_env();
	res = malloc(sizeof(char *) * count + 1);
	while (i < count)
	{
		res[i] = ft_strjoin(temp->content->envname, "=");
		res[i] = ft_strjoin(res[i], temp->content->envval);
		temp = temp->next;
		++i;
	}
	res[i] = NULL;
	return (res);
}
