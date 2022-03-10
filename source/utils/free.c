/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <htumanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:41:10 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/08 16:19:25 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_2d(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	clear_memory()
{
	
}

void	clear_globs( void )
{
	// if (g_val.redirects.in.path)
	// {
	// 	free(g_val.redirects.in.path);
	// 	g_val.redirects.in.path = NULL;
	// }
	// if (g_val.redirects.out.path)
	// {
	// 	free(g_val.redirects.out.path);
	// 	g_val.redirects.out.path = NULL;
	// }
	// g_val.redirects.in.level = 0;
	// g_val.redirects.out.level = 0;
}
