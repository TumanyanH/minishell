/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:13:32 by htumanya          #+#    #+#             */
/*   Updated: 2022/04/04 13:30:02 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_objs(char *str)
{
	int	i;
	int	count;
	int	sing_quote;
	int	doub_quote;

	i = 0;
	count = 1;
	sing_quote = 0;
	doub_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !doub_quote)
			sing_quote = !sing_quote;
		else if (str[i] == '\"' && !sing_quote)
			doub_quote = !doub_quote;
		else if (is_space(str[i]) && !sing_quote && !doub_quote)
		{
			++count;
			while (is_space(str[i]))
				++i;
			--i;
		}
		++i;
	}
	return (count);
}

int	count_str_len(char *str)
{
	int	i;
	int	sing_quote;
	int	doub_quote;

	i = 0;
	sing_quote = 0;
	doub_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !doub_quote)
			sing_quote = !sing_quote;
		else if (str[i] == '\"' && !sing_quote)
			doub_quote = !doub_quote;
		else if (is_space(str[i]) && !sing_quote && !doub_quote)
			break ;
		++i;
	}
	return (i);
}

char	*my_substr(char *str, int start, int len)
{
	char	*res;
	int		i;
	int		sing_quote;
	int		doub_quote;

	i = 0;
	sing_quote = 0;
	doub_quote = 0;
	res = malloc(sizeof(char) * len + 1);
	while (str[start] && start < len)
	{
		if (str[start] == '\'' && !doub_quote)
			sing_quote = !sing_quote;
		else if (str[start] == '\"' && !sing_quote)
			doub_quote = !doub_quote;
		else
		{
			res[i] = str[start];
			++i;
		}
		++start;
	}
	res[i] = '\0';
	return (res);
}

char	**my_split(char *str)
{
	char	**res;
	int		count;
	int		i;
	int		cur_len;

	str = ft_strtrim(str, " ");
	count = count_objs(str);
	res = malloc(sizeof(char *) * count + 1);
	i = 0;
	while (i < count)
	{
		str = ft_strtrim(str, " ");
		cur_len = count_str_len(str);
		res[i] = my_substr(str, 0, cur_len);
		str = str + cur_len;
		++i;
	}
	res[i] = NULL;
	return (res);
}
