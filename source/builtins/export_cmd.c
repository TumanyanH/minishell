/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:34:09 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/10 21:45:37 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_print(void)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = g_val.env;
	while (temp != NULL)
	{
		printf("declare -x %s=\"%s\"\n",
			temp->content->envname, temp->content->envval);
		temp = temp->next;
	}
}

void	export_error(char *cmd)
{
	int	i;

	i = 0;
	printf("minishell: export: '%s': not a valid identifier\n", cmd);
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

int	check_export(int fd, char **args)
{
	int			i;
	char		**new;
	t_env_item	*item;
	t_list		*temp;

	i = 0;
	if (args[0][0] == '\0')
		export_print();
	else
	{
		while (args[i])
		{
			if (equal_finder(args[i]))
			{
				new = ft_split_by_eq(args[i]);
				temp = find_env(new[0]);
				if (!temp)
				{
					item = (t_env_item *)malloc(sizeof(t_env_item));
					item->envname = new[0];
					item->envval = new[1];
					item->env_print = 1;
					ft_lstadd_back(&g_val.env, ft_lstnew(item));
				}
				else
					temp->content->envval = new[1];
			}
			else
			{
				temp = find_env(args[i]);
				if (!temp)
				{
					item = (t_env_item *)malloc(sizeof(t_env_item));
					item->envname = args[i];
					item->envval = NULL;
					item->env_print = 0;
					ft_lstadd_back(&g_val.env, ft_lstnew(item));
				}
			}
			++i;
		}
	}
	return (0);
}
