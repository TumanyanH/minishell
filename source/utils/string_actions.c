/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:29:36 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/03 21:31:58 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*to_lower(char *cmd)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * ft_strlen(cmd) + 1);
	i = 0;
	while (cmd[i] && !is_space(cmd[i]))
	{
		res[i] = ft_tolower(cmd[i]);
		++i;
	}
	res[i] = '\0';
	if (cmd)
		free(cmd);
	return (res);
}

int	check_dub_quote(char *str)
{
	int	i;

	i = 1;
	if ((str[0] == 39 || str[0] == 34)
		&& (str[ft_strlen(str) - 1] == 39 || str[ft_strlen(str) - 1] == 34)
		&& (str[ft_strlen(str)] == 39 || str[ft_strlen(str)] == 34))
	{
		while (i < ft_strlen(str) - 1)
		{
			if (str[i] == 39 || str[i] == 34)
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}

char	*quote_skip(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] != '\'' && str[i] != '\"')
			len++;
		++i;
	}
	res = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] != '\'' && str[i] != '\"')
		{
			res[j] = str[i];
			++j;
		}
		++i;
	}
	res[j] = '\0';
	return (res);
}