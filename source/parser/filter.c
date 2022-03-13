/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:10:06 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/13 21:18:03 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    count_till_cont(char *cmd, int *i)
{
    while (cmd[*i] && (cmd[*i] == '<' || cmd[*i] == '>'))
        (*i)++;
    while (cmd[*i] && is_space(cmd[*i]))
        (*i)++;
    while (cmd[*i] && !is_space(cmd[*i]))
        (*i)++;
}

char    *filter_cmd(char *cmd)
{
    int i;
    char *temp;
    int j;
    
    i = 0;
    j = 0;
    temp = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
    while (i < ft_strlen(cmd))
    {
        if (cmd[i] == '<' || cmd[i] == '>')
            count_till_cont(cmd, &i);
        else
        {
            temp[j] = cmd[i];
            j++;
        }
        i++;
    }
    temp[j] = '\0';
    return (temp);
}