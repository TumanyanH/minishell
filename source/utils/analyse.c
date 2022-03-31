/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:09:07 by ster-min          #+#    #+#             */
/*   Updated: 2022/03/31 17:17:47 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_dub_quote(char *str)
{
	int	i;

	i = 1;
	if ((str[0] == 39 || str[0] == 34)
		&& (str[ft_strlen(str) - 1] == 39 || str[ft_strlen(str) - 1] == 34)
		&& (str[ft_strlen(str)] == 39 || str[ft_strlen(str)] == 34))
	{
		while (i < ft_strlen(str) - 1)
		{
			if (str[i] == 39 || str[i] == 34)
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}

char	*to_lower(char *cmd)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * ft_strlen(cmd) + 1);
	i = 0;
	while (cmd[i] && !is_space(cmd[i]))
	{
		res[i] = ft_tolower(cmd[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*quote_skip(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] != '\'' && str[i] != '\"')
			len++;
		++i;
	}
	res = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] != '\'' && str[i] != '\"')
		{
			res[j] = str[i];
			++j;
		}
		++i;
	}
	res[j] = '\0';
	return (res);
}

void	checking_commands(int i, char *command, char *cmd)
{
	char	**temp;
	char	*acc_check;

	command = to_lower(command);
	temp = ft_split(cmd, ' ');
	while (!is_space(*cmd) && *cmd)
		cmd++;
	if (cmd && ft_strncmp(command, "echo\0", 5) == 0)
		check_echo(cmd);
	else if (cmd && ft_strncmp(command, "cd\0", 3) == 0)
		check_cd(cmd);
	else if (cmd && ft_strncmp(command, "pwd\0", 4) == 0)
		check_pwd(cmd);
	else if (cmd && ft_strncmp(command, "export\0", 7) == 0)
		check_export(cmd);
	else if (cmd && ft_strncmp(command, "unset\0", 6) == 0)
		check_unset(cmd);
	else if (cmd && ft_strncmp(command, "env\0", 4) == 0)
		check_env(cmd);
	else
	{
		acc_check = ft_access(command);
		if(cmd && acc_check)
			ft_exec(i, acc_check);
		else
		{
			printf("minishell: %s: command not found\n", temp[0]);
			exit(127);
		}
	}
}

int	check_structure(char *cmd)
{
	int	i;

	i = 0;
	cmd = ft_strtrim(cmd, " ");
	if (cmd[i] == '|')
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '|')
		{
			while (is_space(cmd[++i]))
				;
			if ((cmd[i] == '\0' || cmd[i] == '|'))
				return (0);
		}
		++i;
	}
	return (1);
}

void start_executor()
{
	int i;
	// char	**envars;
	pid_t	pid;

	// envars = list_to_arr();
	
	
}

int	prompt_heredoc(char *delim)
{
	char *read;
	int fd;

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

int find_aprop_in(int i)
{
	int j;
	int fd;

	fd = g_val.cmd_table[i].pipes[0];
	j = 0;
	while (g_val.cmd_table[i].redirects.in[j].path)
	{
		if (fd != g_val.cmd_table[i].pipes[0])
			close(fd);
		if (g_val.cmd_table[i].redirects.in[j].level == 2)
		{
			if (!access("./.tmp", O_RDWR))
				unlink("./.tmp");
			fd = prompt_heredoc(g_val.cmd_table[i].redirects.in[j].path);
			close(fd);
			fd = open("./.tmp", O_RDONLY);
		}
		else
		{
			if (!access(g_val.cmd_table[i].redirects.in[j].path, O_RDONLY))
				fd = open(g_val.cmd_table[i].redirects.in[j].path, O_RDONLY);
			else 
			{
				printf("--minishell: %s: No such file or directory\n", g_val.cmd_table[i].redirects.in[j].path);
				exit(1);
			}
		}
		j++;
	}
	return (fd);
}

int	find_aprop_out(int i)
{
	int fd;
	int	j;
	int perms;

	perms = 0;
	j = 0;
	fd = 1;
	if (i != g_val.pipes_count - 1)
		fd = g_val.cmd_table[i + 1].pipes[1];
	while (g_val.cmd_table[i].redirects.out[j].path)
	{
		printf("mta\n");
		if (fd != g_val.cmd_table[i + 1].pipes[1] && fd != 1)
			close(fd);
		if (g_val.cmd_table[i].redirects.out[j].level == 2)
			fd = open(g_val.cmd_table[i].redirects.out[j].path, O_CREAT | O_RDWR | O_APPEND, 0766);
 		else if (g_val.cmd_table[i].redirects.out[j].level == 1)
			fd = open(g_val.cmd_table[i].redirects.out[j].path, O_CREAT | O_RDWR, 0766);
		if (fd < 0)
		{
			printf("minishell: %s: file can not be created!\n", g_val.cmd_table[i].redirects.out[j].path);
			exit(1);
		}
		j++;
	}
	return (fd);
}

void	analyse_cmd(char *cmd, char **argv)
{
	int		i;
	char	*command;
	pid_t	pid;
	int		fd_in;
	int		fd_out;
	
	if (cmd && ft_strlen(cmd) > 0)
	{
		g_val.pipes_count = count_pipes(cmd, 0) + 1;
		start_parse(cmd);
		i = -1;
		while (++i < g_val.pipes_count)
		{
			cmd = ft_strtrim(g_val.cmd_table[i].cmd, " ");
			command = quote_skip(cmd);
			if (cmd && ft_strncmp(command, "exit\0", 5) == 0)
			{
				while (*cmd && !is_space(*cmd))
					cmd++;
				check_exit(cmd);
			}
			pid = fork();
			if (pid < 0)
				printf("Error: fork not forked\n");
			else if (!pid)
			{
				if (g_val.cmd_table[i].has_pipe || g_val.cmd_table[i].redirects.in[0].path)
				{
					fd_in = find_aprop_in(i);
					dup2(fd_in, STDIN_FILENO);
				}
				dup2(STDOUT_FILENO, g_val.cmd_table[i].pipes[1]);
				close(g_val.cmd_table[i].pipes[1]);
				// fd_out = find_aprop_out(i);
				// printf("out fd = %d\n", fd_out);
				// if (fd_out != 1)
					dup2(fd_out, STDOUT_FILENO);
				checking_commands(i, command, cmd);
			}
			else
			{
				if (i < g_val.pipes_count)
					close (g_val.cmd_table[i].pipes[1]);
				waitpid(pid, NULL, 0);
			}
		}
		// clear_globs();
	}
}
