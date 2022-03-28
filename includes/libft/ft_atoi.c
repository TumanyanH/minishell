/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:09:17 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/26 17:33:50 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_writer(char *str, int quote)
{
	int	i;

	i = 0;
	printf("minishell: exit: ");
	if (quote == 2)
	{
		while (!is_space(str[i]) && str[i])
		{
			printf("%c", str[i]);
			++i;
		}
	}
	else
	{
		while (str[i])
		{
			printf("%c", str[i]);
			++i;
		}
	}
	printf(": numeric argument required\n");
	exit (255);
}

int	ft_atoi(char *str, int *check, int quote)
{
	int		i;
	unsigned long long		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 0;
	*check = 0;
	while (is_space(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = 1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (is_space(str[i]))
	{
		while (is_space(str[i]) && str[i])
			++i;
		if (str[i] != '\0' && quote == 2)
		{
			printf("minishell: exit: too many arguments\n");
			*check = 1;
		}
	}
	if (str[i] != '\0' && *check != 1)
		error_writer(str, quote);
	if (sign == 1)
		res *= -1;
	return (res);
}
