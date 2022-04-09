/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:33:13 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/03 21:33:40 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	prompt_heredoc(char *delim, int i)
{
	char	*read;
	int		fd;
	char	*temp;
	char	*temp2;

	temp = NULL;
	fd = 0;
	while (1)
	{
		read = readline(">");
		if (!ft_strncmp(read, delim, ft_strlen(read)))
			break ;
		else
		{
			temp = ft_strjoin(temp, read);
			temp = ft_strjoin(temp, "\n");
		}
	}
	fd = g_val.pipes[i][0];
	if (temp != NULL)
		write(g_val.pipes[i][1], temp, ft_strlen(temp));
	close(g_val.pipes[i][1]);
	return (fd);
}