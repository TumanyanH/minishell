/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:27 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/16 20:09:50 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*atoi_helper(char *str, int *quote)
{
	int		i;
	int		index;
	char	*ret;

	i = 0;
	index = 0;
	*quote = 0;
	ret = malloc(sizeof(char) * ft_strlen(str));
	while (is_space(str[i]))
		++i;
	if (str[i] != 39 && str[i] != 34)
		*quote += 1;
	while (str[i])
	{
		if (str[i] != 39 && str[i] != 34)
			ret[index++] = str[i];
		++i;
	}
	while (is_space(str[i]))
		--i;
	if (str[i] != 39 && str[i] != 34)
		*quote += 1;
	return (ret);
}

void	ft_exit(unsigned long long ret_val)
{
	printf("exit\n");
	exit(ret_val);
}

void	ret_xcho(int ret)
{
	if (ret >= 0 && ret <= 255)
		ft_exit(ret);
	else if (ret < 0)
	{
		while (ret < 0)
			ret += 256;
		ft_exit(ret);
	}
}

void	check_exit(char *cmd)
{
	unsigned long long	ret;
	int					checker;
	int					quote;

	if (*cmd == '\0')
		ft_exit(0);
	else if (is_space(*cmd))
	{
		ret = ft_atoi(atoi_helper(cmd, &quote), &checker, quote);
		if (checker == 0 && (int)ret < 0)
			ret_xcho(ret);
		else if ((unsigned long long)ret > 9223372036854775807)
		{
			printf("minishell: exit: %s: numeric argument required\n",
				ft_itoa(ret));
			ft_exit(255);
		}
		else if ((int)ret >= 0 && checker == 0)
			ft_exit(ret % 256);
	}
}
