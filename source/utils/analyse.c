#include "../../includes/minishell.h"

void	analyse_cmd(char *cmd)
{
	if (cmd)
	{
		add_history(cmd);
		check_exit(cmd);
	}
}