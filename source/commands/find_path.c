/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/13 16:44:17 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_item	*find_env(t_list *env, char *envname)
{
	while (ft_strncmp(env->content->envname, envname,
			ft_strlen(env->content->envname)) != 0)
	{
		env = env->next;
	}
	return (env->content);
}

// void	find_path(char **path, char **envp)
// {
// 	char	*path_var;
// 	char	**temp;
// 	int		i;

// 	i = -1;
// 	path_var = envp[find_env(envp, "PATH")];
// 	path_var += 5;
// 	temp = ft_split(path_var, ':');
// 	while (temp[++i])
// 	{
// 		*path = ft_strjoin(temp[i], "/whereis");
// 		if (access(*path, F_OK) == 0)
// 			break ;
// 	}
// }
