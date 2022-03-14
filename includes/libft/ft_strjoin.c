/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:26:29 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/14 17:42:49 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	newstrlen;
	char	*newstr;

	newstrlen = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char *) * newstrlen + 1);
	if (!newstr)
		return (NULL);
	while (s1 && *s1 != '\0')
	{
		*newstr = *s1;
		++s1;
		++newstr;
	}
	while (s2 && *s2 != '\0')
	{
		*newstr = *s2;
		++s2;
		++newstr;
	}
	*newstr = '\0';
	return (newstr - newstrlen);
}
