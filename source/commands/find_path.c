/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/10 19:22:07 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_env(char **envp, char *envname)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], envname, ft_strlen(envname)) != 0)
		i++;
	return (i);
}

void	find_path(char **path, char **envp)
{
	char	*path_var;
	char	**temp;
	int		i;

	i = -1;
	path_var = envp[find_env(envp, "PATH")];
	path_var += 5;
	temp = ft_split(path_var, ':');
	while (temp[++i])
	{
		*path = ft_strjoin(temp[i], "/whereis");
		if (access(*path, F_OK) == 0)
			break ;
	}
}
