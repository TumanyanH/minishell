/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:25:14 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:25 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	len_till_space(char *str)
{
	int	i;

	i = 0;
	while (!is_space(str[i]))
		++i;
	return (i);
}

char	*quote_split(char *str, int *i)
{
	printf("i=%d\n", *i);
	return (str);
}

char	**arg_split(char *str)
{
	int		i;
	char	**res;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			quote_split(str, &i);
		if (!is_space(str[i]))
		{
			len_till_space(str);
		}
		++i;
	}
	return (res);
}
