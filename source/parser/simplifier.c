/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:20:44 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/14 18:41:50 by ster-min         ###   ########.fr       */
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
	if (temp)
		free(temp);
	return (temp2);
}

int	minichek(char *cmd, int i)
{
	printf("FUCK\n");
	if (i == 0)
		return (1);
	else if (cmd[i - 1] == '\'' || cmd[i - 1] == '\"' || is_space(cmd[i - 1]))
		return (1);
	else
		return (0);
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
		if (cmd[i] == '\"' && !quote_det)
			doub_quote_det = !doub_quote_det;
		if (cmd[i] == '\'' && !doub_quote_det)
			quote_det = !quote_det;
		if (cmd[i] == '$' && !quote_det && !is_space(cmd[i + 1]))// && minichek(cmd, i))
		{
			tmp = ft_substr(cmd, 0, i);
			name = find_var_name(cmd, i);
			tmp = ft_strjoin(tmp, find_env(name));
			if (name)
				free(name);
			tmp2 = ft_substr(cmd, i + count_var_len(cmd, i),
				ft_strlen(cmd) - i - count_var_len(cmd, i));
			cmd = ft_strjoin(tmp, tmp2);
			printf("asd\n");
			i = -1;
		}
		++i;
	}
	return (cmd);
}
