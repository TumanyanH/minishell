/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:20:44 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/13 20:02:32 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_var_len(char *s, int i)
{
	int	len;

	len = 0;
	while (!is_space(s[i]))
	{
		++i;
		++len;
	}
	return (len);
}

char	*find_var_name(char *cmd, int i)
{
	int	j;
	char *temp;
	char *temp2;
	
	j = i + 1;
	while (cmd[j] && !is_space(cmd[j]))
		++j;
	temp = ft_substr(cmd, i + 1, j - i);
	temp2 = ft_strtrim(temp, "{}");
	free(temp);
	return (temp2);
}

char	*find_var(char *name)
{
	t_list *temp;

	temp = g_val.env;
	while (ft_strncmp(temp->content->envname, name, ft_strlen(temp->content->envname)))
	{
		printf("lala\n");
		temp = g_val.env->next;
	}
	return (temp->content->envval);
}

char	*simplifier(char *cmd)
{
	int		i;
	int		quote_det;
	char	*tmp;
	char	*tmp2;
	char	*name;
	
	i = 0;
	quote_det = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '\'')
			quote_det = !quote_det;
		if (cmd[i] == '$' && !quote_det && !is_space(cmd[i + 1]))
		{
			tmp = ft_substr(cmd, 0, i);
			name = find_var_name(cmd, i);
			tmp = ft_strjoin(tmp, find_env(name));
			free(name);
			tmp2 = ft_substr(cmd, i + count_var_len(cmd, i),
				ft_strlen(cmd) - i - count_var_len(cmd, i));
			tmp = ft_strjoin(tmp, tmp2);
			cmd = tmp;
			i = -1;
		}
		++i;
	}
	return (cmd);
}