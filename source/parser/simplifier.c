/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:20:44 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/15 20:05:29 by ster-min         ###   ########.fr       */
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
	int	j;
	char *temp;
	char *temp2;

	j = i + 1;
	printf("var=%s\n", cmd + i);
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

	i = 0;
	quote_det = 0;
	doub_quote_det = 0;
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
			tmp = ft_strjoin(tmp, find_env(name));
			if (name)
				free(name);
			tmp2 = ft_substr(cmd, i + count_var_len(cmd, i),
				ft_strlen(cmd) - i - count_var_len(cmd, i));
			cmd = ft_strjoin(tmp, tmp2);
			i = -1;
		}
		++i;
	}
	return (cmd);
}
