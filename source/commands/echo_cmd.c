/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:05:37 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/13 21:32:34 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	string_printer(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '"')
	{
		printf("%c", str[i]);
		++i;
	}
	return (i + 1);
}

int	print_space(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		++i;
	printf(" ");
	return (i - 1);
}

int	option(char *cmd)
{
	if (ft_strncmp(cmd, "-n", 2) == 0)
	{
		if (*(cmd + 2) == '\0' || is_space(*(cmd + 2)))
			return (1);
	}
	return (0);
}

void	check_echo(char *cmd)
{
	int	k;

	k = 0;
	if (is_space(*cmd) == 0 && *cmd != '\0')
		printf("minishell: echo%s: command not found\n", cmd);
	else
	{
		while (is_space(*cmd))
			cmd++;
// -n ov readline y cbxuma :D
		k = option(cmd);
		if (k)
			cmd += 3;
		while (*cmd)
		{
			if (*cmd == '"')
				cmd += string_printer(cmd);
			if (is_space(*cmd))
				cmd += print_space(cmd);
			else
				printf("%c", *cmd);
			cmd++;
		}
		if (k == 0)
			printf("\n");
	}
}

