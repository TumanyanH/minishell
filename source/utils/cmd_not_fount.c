/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_fount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:52:58 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/10 20:52:59 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_not_found(char *cmdname)
{
	printf("minishell: %s: command not found\n", cmdname);
}
