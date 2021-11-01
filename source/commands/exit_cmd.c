#include "../../includes/minishell.h"

void	successful_exit()
{
	clear_history();
	exit(0);
}

void	check_exit(char *cmd)
{
	// initial ctrl + c to initilaizer
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		exit(0);
}

void	exit_keypass()
{
	struct sigaction sa;

    sa.sa_handler = successful_exit;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}