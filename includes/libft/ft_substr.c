/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ster-min <ster-min@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:02:21 by htumanya          #+#    #+#             */
/*   Updated: 2022/03/15 17:03:18 by ster-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	over_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	over_len = ft_strlen(s + start);
	s_len = ft_strlen(s);
	if (len > over_len)
		len = over_len;
	if (start > s_len)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && (size_t)start + i < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
