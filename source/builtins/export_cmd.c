/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:34:09 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/11 20:53:19 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export_print(void)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = g_val.env;
	while (temp != NULL)
	{
		if (temp->content->env_print == 1)
			printf("declare -x %s=\"%s\"\n",
				temp->content->envname, temp->content->envval);
		else
			printf("declare -x %s\n",
				temp->content->envname);
		temp = temp->next;
	}
	return (0);
}

int	equal_finder(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		++i;
	}
	return (0);
}

void	export_add(char *name, char *value, int print)
{
	t_env_item	*item;

	item = (t_env_item *)malloc(sizeof(t_env_item));
	item->envname = name;
	item->envval = value;
	item->env_print = print;
	ft_lstadd_back(&g_val.env, ft_lstnew(item));
}

void	eq_export(char *str)
{
	char		**new;
	t_list		*temp;

	new = ft_split_by_eq(str);
	temp = find_env(new[0]);
	if (!temp)
		export_add(new[0], new[1], 1);
	else
	{
		temp->content->envval = ft_strjoin(NULL, new[1]);
		temp->content->env_print = 1;
	}
}

int	check_export(int fd, char **args)
{
	int			i;
	t_list		*temp;

	i = -1;
	if (args[0][0] == '\0')
		return (export_print());
	while (args[++i])
	{
		if (ft_isdigit(args[i][0]))
			printf("minishell: export: '%s': not a valid identifier\n",
				args[i]);
		if (equal_finder(args[i]))
			eq_export(args[i]);
		else
		{
			temp = find_env(args[i]);
			if (!temp)
				export_add(args[i], NULL, 0);
		}
	}
	return (0);
}
