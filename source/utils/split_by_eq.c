/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_eq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:17:11 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/20 03:44:00 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_till_eq(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

char	**ft_split_by_eq(char const *s)
{
	char	**splited;
	int		i;
	int		eq;

	eq = count_till_eq(s);
	i = 0;
	splited = (char **)malloc(2 * sizeof(char *));
	splited[0] = (char *)malloc(eq + 1 * sizeof(char));
	splited[1] = (char *)malloc(ft_strlen(s + eq + 1) + 1
			* sizeof(char));
	while (s[i] != '\0')
	{
		if (i <= eq)
		{
			if (s[i] != '=')
				splited[0][i] = s[i];
		}
		else
			splited[1][i - eq - 1] = s[i];
		++i;
	}
	splited[0][eq] = '\0';
	splited[1][i - eq - 1] = '\0';
	return (splited);
}
