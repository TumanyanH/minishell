#include "../../includes/minishell.h"

void successful_exit()
{

}

void check_exit(char *cmd)
{
	// initial ctrl + c to initilaizer
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		exit(0);
}