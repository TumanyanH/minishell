/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirects_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:16:32 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/16 19:47:10 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_fp(char *cmd)
{
	int	i;

	i = 0;
	while (!is_space(cmd[i]) && cmd[i] && cmd[i] != '<' && cmd[i] != '>')
		++i;
	return (i);
}

char	*find_file(char *cmd, int *i)
{
	char	*fp;
	int		count;

	while (is_space(cmd[*i]))
		++(*i);
	count = count_fp(&(cmd[*i]));
	fp = (char *)malloc(sizeof(char) * (count + 1));
	ft_strlcpy(fp, (cmd + *i), count + 1);
	*i += ft_strlen(fp);
	if (fp[0] == '\0')
	{
		printf("minishell: syntax error near unexpected token\n");
		return (NULL);
	}
	return (fp);
}

int	count_redirects(char *cmd, char red_type)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == red_type)
		{
			if (cmd[i + 1] == red_type)
				++i;
			++count;
		}
		++i;
	}
	return (count);
}
