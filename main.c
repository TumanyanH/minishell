/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:30:26 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/24 21:22:12 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_clear_screen(void)
// {
// 	char buf[1024];
//     char *str;

//     tgetent(buf, getenv("TERM"));
//     str = tgetstr("cl", NULL);
//     fputs(str, stdout);
// }

int	main(void)
{
	write(1, "\033[2J", 4);
	write(1, "\033[H", 3);
	printf("Hello World!\n");
	return (0);
}
