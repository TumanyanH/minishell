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
			if (temp)
				temp = ft_strjoin(temp, "\n");
			temp = ft_strjoin(temp, read);
		}
	}
	// fd = dup(g_val.pipes[i][1]);
	printf("%s---\n",temp);
	write(fd, temp, ft_strlen(temp));
	return (fd);
}