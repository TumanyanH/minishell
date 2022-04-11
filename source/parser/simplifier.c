/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:20:44 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/21 20:42:41 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_var_len(char *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && !is_space(s[i]))
	{
		++i;
		++len;
	}
	return (len);
}

char	*find_var_name(char *cmd, int i)
{
	int		j;
	char	*temp;
	char	*temp2;

	j = i + 1;
	if (!cmd[j])
		return (NULL);
	while (cmd[j] && !is_space(cmd[j]))
		++j;
	temp = ft_substr(cmd, i + 1, j - i);
	temp2 = ft_strtrim(temp, "{}");
	free(temp);
	return (temp2);
}

char	*simplifier(char *cmd)
{
	int		i;
	int		quote_det;
	char	*tmp;
	char	*tmp2;
	char	*name;
	int		doub_quote_det;
	t_list	*temp;

	i = 0;
	quote_det = 0;
	doub_quote_det = 0;
	printf("start=%s---\n", cmd);
	while (cmd[i] != '\0')
	{
		name = NULL;
		if (cmd[i] == '\"' && !quote_det)
			doub_quote_det = !doub_quote_det;
		else if (cmd[i] == '\'' && !doub_quote_det)
			quote_det = !quote_det;
		else if (!quote_det && cmd[i] == '$' && !is_space(cmd[i + 1]))
		{
			tmp = ft_substr(cmd, 0, i);
			name = find_var_name(cmd, i);
			if (!ft_strncmp(name, "?", ft_strlen(name)))
				tmp = ft_strjoin(tmp, ft_itoa(g_val.last_returned));
			else
			{
				temp = find_env(name);
				if (temp)
					tmp = ft_strjoin(tmp, temp->content->envval);
			}
			if (name)
				free(name);
			tmp2 = ft_substr(cmd, i + count_var_len(cmd, i),
					ft_strlen(cmd) - i - count_var_len(cmd, i));
			cmd = ft_strjoin(tmp, tmp2);
			i = -1;
		}
		++i;
	}
	printf("simp=%s---\n", cmd);
	return (cmd);
}
