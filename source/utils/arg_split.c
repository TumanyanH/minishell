/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:25:14 by ster-min          #+#    #+#             */
/*   Updated: 2022/02/24 22:11:26 by htumanya         ###   ########.fr       */
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

int count_till_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39)
			return (i);
		++i;
	}
	return (-1);
}

int	count_quotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 34 || str[i] == 39)
			++count;
		++i;
	}
	return (count);
}

char	*quote_split(char *str, int *i)
{
	char	*res;
	int		count;

	res = NULL;
	count = count_till_quote(&(str[*i + 1]));

	if (!ft_isalpha(str[*i + 1]))
	{
		export_error(str);
		return (res);
	}
	if (count > 0)
	{
		res = (char *)malloc(sizeof(char) * (count + 2));
		ft_strlcpy(res, str + *i + 1, count + 1);
		i += count + 1;
	}
	return (res);
}

char	**arg_split(char *str)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * ((count_quotes(str) / 2) + 1));
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			res[j] = quote_split(str, &i);
			if (res[j] != NULL)
				j++;
		}
		if (!is_space(str[i]))
		{
			len_till_space(&(str[i]));
		}
		++i;
	}
	res[j] = NULL;
	return (res);
}


