/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:48:23 by htumanya          #+#    #+#             */
/*   Updated: 2022/02/16 21:40:09 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_env_item *content)
{
	t_list	*obj;

	obj = malloc(sizeof(t_list));
	if (!obj)
		return (NULL);
	obj->content = content;
	obj->next = NULL;
	obj->prev = NULL;
	return (obj);
}
