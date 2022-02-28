/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:01:42 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/28 22:11:32 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int start_parse(char *cmd_line)
{
    int i;

    i = 0;
    while (cmd_line[i])
    {
        if (cmd_line[i] == '>' || cmd_line[i] == '<')
        {
            parse_redirects(cmd_line, &i);
            
        }
        ++i;
    }
}