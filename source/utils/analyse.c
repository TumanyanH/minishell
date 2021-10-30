#include "../../includes/minishell.h"

void	analyse_cmd(char *cmd)
{
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		exit(0);
	
}