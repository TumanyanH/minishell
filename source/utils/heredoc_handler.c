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

int	prompt_heredoc(char *delim)
{
	char	*read;
	int		fd;

	fd = open("./.tmp", O_CREAT | O_RDWR | O_APPEND, 0766);
	while (1)
	{
		read = readline(">");
		if (!ft_strncmp(read, delim, ft_strlen(read)))
			break ;
		else
		{
			write(fd, read, ft_strlen(read));
			write(fd, "\n", 1);
		}
	}
	return (fd);
}