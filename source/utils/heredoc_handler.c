/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:33:13 by ster-min          #+#    #+#             */
/*   Updated: 2022/04/16 18:38:45 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*read_heredoc(char *delim)
{
	char	*read;
	char	*temp;
	char	*temp2;

	temp = NULL;
	while (1)
	{
		read = readline(">");
		if (!ft_strncmp(read, delim, ft_strlen(delim)))
			break ;
		else
		{
			temp2 = ft_strjoin(temp, read);
			free(temp);
			temp = ft_strjoin(temp2, "\n");
		}
	}	
	return (temp);
}

void	sigkill(int a)
{
	printf("HEY\n");
	exit(0);
}

int	pr_heredoc(char *delim, int i)
{
	char	*read;
	int		fd[2];
	char	*temp;
	char	*temp2;
	pid_t	pid;

	pid = fork();
	pipe(fd);
	if (pid < 0)
		printf("something gone wrong\n");
	else if (pid == 0)
	{
		signal(SIGINT, sigkill);
		temp = read_heredoc(delim);
	}
	else
		wait(NULL);
	if (temp != NULL)
	{
		write(fd[1], temp, ft_strlen(temp));
		free(temp);
	}
	close(fd[1]);
	return (fd[0]);
}
